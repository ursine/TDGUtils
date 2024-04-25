//
// Created by gcoulbourne on 4/17/24.
// Based on code http://github.com/fromgetml/reflect-cpp under MIT license

#pragma once

#include <string_view>
#include <source_location>
#include <string>
#include <array>
#include <utility>

namespace TDG::internal {

// StringLiteral -------------
/// Normal strings cannot be used as template
/// parameters, but this can. This is needed
/// for the parameters names in the NamedTuples.

template <size_t N>
struct StringLiteral {
    constexpr explicit StringLiteral(const auto... _chars) : arr_{_chars..., '\0'} {}

    constexpr explicit StringLiteral(const char (&_str)[N]) {
        std::copy_n(_str, N, std::data(arr_));
    }

    /// Returns the value as a string.
    [[nodiscard]] std::string str() const { return std::string(std::data(arr_), N - 1); }

    /// Returns the value as a string.
    [[nodiscard]] constexpr std::string_view string_view() const {
        return std::string_view(std::data(arr_), N - 1);
    }

    std::array<char, N> arr_{};
};

template <size_t N1, size_t N2>
constexpr inline bool operator==(const StringLiteral<N1>& _first,
                                 const StringLiteral<N2>& _second) {
    if constexpr (N1 != N2) {
        return false;
    }
    return _first.string_view() == _second.string_view();
}

template <size_t N1, size_t N2>
constexpr inline bool operator!=(const StringLiteral<N1>& _first,
                                 const StringLiteral<N2>& _second) {
    return !(_first == _second);
}

// End StringLiteral ------------------------

template <class T>
consteval auto get_type_name_str_view() {
    // Unfortunately, we cannot avoid the use of a compiler-specific macro for
    // Clang on Windows. For all other compilers, function_name works as intended.
#if defined(__clang__) && defined(_MSC_VER)
    const auto func_name = std::string_view{__PRETTY_FUNCTION__};
#else
    const auto func_name =
            std::string_view{std::source_location::current().function_name()};
#endif
#if defined(__clang__) || defined(__GNUC__)
    const auto split = func_name.substr(0, func_name.size() - 1);
    return split.substr(split.find("T = ") + 4);
#elif defined(_MSC_VER)
  auto split = func_name.substr(0, func_name.size() - 7);
  split = split.substr(split.find("get_type_name_str_view<") + 23);
  auto pos = split.find(" ");
  if (pos != std::string_view::npos) {
    return split.substr(pos + 1);
  }
  return split;
#else
  static_assert(
      false,
      "You are using an unsupported compiler. Please use GCC, Clang "
      "or MSVC or explicitly tag your structs using 'Tag' or 'Name'.");
#endif
}


}

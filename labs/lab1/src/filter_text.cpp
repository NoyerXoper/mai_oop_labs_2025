#include <string>
#include <sstream>
#include <concepts>
#include "filter_text.hpp"

#include <iostream>

namespace {
    inline bool IsNumber(char ch) {
        return '0' <= ch && ch <= '9';
    }
}


template<std::integral T = int>
std::vector<T> GetNumbersFromString(const std::string& text) noexcept {
    bool did_number_end = true;
    std::vector<T> numbers;
    T current_number(0);

    for (char ch: text) {
        if (IsNumber(ch)) {
            current_number = static_cast<T>(10) * current_number + static_cast<T>(ch - '0');
            did_number_end = false;
        } else if (!did_number_end){
            did_number_end = true;
            numbers.push_back(current_number);
            current_number = T(0);
        }
    }

    if (!did_number_end) {
        numbers.push_back(current_number);
    }
    return numbers;
}

template<>
std::vector<std::string> GetNumbersFromString(const std::string& text) noexcept {
    bool did_number_end = true;
    std::vector<std::string> numbers;
    std::string current_number;

    for (char ch: text) {
        if (IsNumber(ch)) {
            current_number.push_back(ch);
            did_number_end = false;
        } else if (!did_number_end){
            did_number_end = true;
            numbers.push_back(std::move(current_number));
            current_number = "";
        }
    }

    if (!did_number_end) {
        numbers.push_back(std::move(current_number));
    }
    return numbers;

}

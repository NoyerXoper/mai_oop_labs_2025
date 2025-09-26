#pragma once

#include <memory>
#include <seven.hpp>
#include <initializer_list>
#include <stdexcept>

namespace {
inline std::size_t mod7_diff(std::size_t a, std::size_t b) {
    return a > b ? (a - b) % 7 : (7 + a - b) % 7;
}
}

namespace Seven {
Seven::Seven() = default;
Seven::Seven(std::size_t size, unsigned char ch): _digits(size, ch) {}
Seven::Seven(const std::initializer_list<unsigned char>& il): _digits(il) {}
Seven::Seven(const std::string& str): _digits(str.size()) {
    for(auto it = str.rbegin(); it != str.rend(); ++it) {
        _digits.PushBack(*it);
    }
}
Seven::Seven(std::size_t size): _digits(size) {}

Seven::Seven(const Seven& other) = default;
Seven::Seven(Seven&& other) noexcept = default;
Seven::~Seven() noexcept = default;


bool Seven::Equals(const Seven& other) const noexcept {
    return _digits.Equals(other._digits);
}
bool Seven::Smaller(const Seven& other) const noexcept {
    if (_digits.Size() > other._digits.Size()) {
        return true;
    }
    if (_digits.Size() < other._digits.Size()) {
        return false;
    }

    for (int i = _digits.Size() - 1; i > 0; --i) {
        if (_digits.Get(i) > other._digits.Get(i)) {
            return true;
        }
        if (_digits.Get(i) < other._digits.Get(i)) {
            return false;
        }
    }
    return _digits.Get(0) > other._digits.Get(0);
}
bool Seven::Greater(const Seven& other) const noexcept {
    if (_digits.Size() < other._digits.Size()) {
        return true;
    }
    if (_digits.Size() > other._digits.Size()) {
        return false;
    }

    for (int i = _digits.Size() - 1; i > 0; --i) {
        if (_digits.Get(i) < other._digits.Get(i)) {
            return true;
        }
        if (_digits.Get(i) > other._digits.Get(i)) {
            return false;
        }
    }
    return _digits.Get(0) < other._digits.Get(0);
}

Seven Add(const Seven& first, const Seven& second) {
    Seven result(std::max(first._digits.Size(), second._digits.Size()) + 1);

    std::size_t minLength = std::min(first._digits.Size(), second._digits.Size());
    std::size_t carry = 0;
    std::size_t digit;

    for (int i = 0; i < minLength; ++i) {
        digit = first._digits.Get(i) + second._digits.Get(i) + carry;
        result._digits.PushBack(digit % 7);
        carry = digit > 7;
    } 

    for (int i = minLength; i < first._digits.Size(); ++i) {
        digit = first._digits.Get(i) + carry;
        result._digits.PushBack(digit % 7);
        carry = digit > 7;
    }
    for (int i = minLength; i < second._digits.Size(); ++i) {
        digit = second._digits.Get(i) + carry;
        result._digits.PushBack(digit % 7);
        carry = digit > 7;
    }
    return result;
}

Seven Subtract(const Seven& first, const Seven& second) {
    if (first._digits.Size() < second._digits.Size()) {
        throw std::invalid_argument("First number must be greater or equal to second");
    }
    Seven result(std::max(first._digits.Size(), second._digits.Size()));

    std::size_t minLength = std::min(first._digits.Size(), second._digits.Size());
    std::size_t carry = 0;
    std::size_t digit;

    for (int i = 0; i < minLength; ++i) {
        digit = mod7_diff(mod7_diff(first._digits.Get(i), second._digits.Get(i)), carry);
        result._digits.PushBack(digit);
        carry = (second._digits.Get(i) + carry) > first._digits.Get(i);
    } 

    for (int i = minLength; i < first._digits.Size(); ++i) {
        digit = mod7_diff(first._digits.Get(i), carry);
        result._digits.PushBack(digit);
        carry = carry > first._digits.Get(i);
    }
    if (carry) {
        throw std::invalid_argument("First number must be greater or equal to second");
    }
    return result;
}
}
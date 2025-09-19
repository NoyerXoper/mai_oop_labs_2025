#pragma once

#include <memory>
#include <headers/seven.hpp>
#include <stdexcept>

namespace {
inline unsigned char true_mod(char a, unsigned char base) {
    return a > 0 ? a % base : (base + a % base) % base;
}
} 


Seven::Seven(): size_(0), capacity_(0), data_(nullptr) {}

Seven::Seven(size_t size, unsigned char ch): size_(size), capacity_(size), data_(new unsigned char[capacity_]) {
    for (int i = 0; i < size; ++i) {
        data_[i] = ch;
    }
}

Seven::Seven(const std::initializer_list<unsigned char>& il): size_(il.size()), capacity_(il.size()), data_(new unsigned char[capacity_]){
    
    int i = size_ - 1;
    for (unsigned char ch: il) {
        data_[i] = ch;
        --i;
    }
}

Seven::Seven(const std::string& str): size_(str.size()), capacity_(str.size()), data_(new unsigned char[capacity_]){
    int i = size_ - 1;
    for (unsigned char ch: str) {
        data_[i] = ch;
        --i;
    }
}

Seven::Seven(const Seven& other): size_(other.size_), data_(new unsigned char[size_]) {
    std::uninitialized_copy(other.data_, other.data_ + size_, data_);
}

Seven::Seven(Seven&& other) noexcept : size_(other.size_), capacity_(other.capacity_), data_(other.data_) {
    other.size_ = 0;
    other.capacity_ = 0;
    other.data_ = nullptr;
}

Seven::~Seven() {
    delete[] data_;
}

void Seven::Swap(Seven& other) {
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
    std::swap(data_, other.data_);
}

Seven& Seven::operator=(const Seven& other) {
    Seven temp = other;
    this->Swap(temp);
    return *this;
}

Seven& Seven::operator=(Seven&& other) {
    Seven temp = std::move(other);
    this->Swap(temp);
    return *this;
}

Seven Seven::Plus(const Seven& other) const {
    Seven result(std::max(size_, other.size_) + 1, 0);
    size_t current_digit = 0;
    size_t min_size = std::min(size_, other.size_);
    size_t carry = 0;
    for (; current_digit < min_size; ++current_digit) {
        result.data_[current_digit] = data_[current_digit] + other.data_[current_digit] + carry;
        carry = result.data_[current_digit] > 6;
        result.data_[current_digit] %= 7;
    }

    while (current_digit < size_) {
        result.data_[current_digit] = data_[current_digit] + carry;
        carry = result.data_[current_digit] > 6;
        result.data_[current_digit] %= 7;
        ++current_digit;
    }

    while (current_digit < other.size_) {
        result.data_[current_digit] = other.data_[current_digit] + carry;
        carry = result.data_[current_digit] > 6;
        result.data_[current_digit] %= 7;
        ++current_digit;
    }

    return result;
}

Seven Seven::Minus(const Seven& other) const {
    if (size_ < other.size_) {
        throw std::invalid_argument("First number must be larger than second: the length of first number is smaller that the length of the second number.");
    } 

    Seven result(size_, 0);
    char carry;
    char temp;
    size_t i;
    size_t last_non_zero_number;
    

    for (i = 0; i < other.size_; ++i) {
        temp = data_[i] - other.data_[i] - carry;
        carry = temp < 0;
        result.data_[i] = true_mod(temp, 7);
        if (result.data_[i] != 0) {
            last_non_zero_number = i;
        }
    }

    for (; i < size_; ++i) {
        temp = data_[i] - carry;
        carry = temp < 0;
        result.data_[i] = true_mod(temp, 7);
        if (result.data_[i] != 0) {
            last_non_zero_number = i;
        }
    }

    if (carry != 0) {
        throw std::invalid_argument("First number must be larger that second");
    }

    result.size_ = i + 1;
    return result;
}

bool Seven::Equals(const Seven& other) const {
    if (size_ != other.size_) {
        return false;
    }

    int i = 0;
    while (i < size_) {
        if (data_[i] != other.data_[i]) {
            return false;
        }
    }
    return true;
}

bool Seven::Smaller(const Seven& other) const {
    if (size_ < other.size_) return true;
    if (size_ > other.size_) return false;

    int i = size_ - 1;
    while (i >= 0) {
        if (data_[i] < other.data_[i]) {
            return true;
        }
        if (data_[i] > other.data_[i]) {
            return false;
        }
        --i;
    } 
    return false;
}

bool Seven::Bigger(const Seven& other) const {
    if (size_ < other.size_) return false;
    if (size_ > other.size_) return true;

    int i = size_ - 1;
    while (i >= 0) {
        if (data_[i] < other.data_[i]) {
            return false;
        }
        if (data_[i] > other.data_[i]) {
            return true;
        }
        --i;
    } 
    return false;

}

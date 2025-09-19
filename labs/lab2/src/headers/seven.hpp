#pragma once

#include <cstddef>
#include <initializer_list>
#include <string>

class Seven {
public:
    Seven();
    Seven(size_t size, unsigned char ch);
    Seven(const std::initializer_list<unsigned char>& il);
    Seven(const std::string& str);

    Seven(const Seven& other);
    Seven(Seven&& other) noexcept;
    virtual ~Seven() noexcept;

    Seven& operator=(const Seven& other);
    Seven& operator=(Seven&& other);

    Seven Plus(const Seven& other) const noexcept;
    Seven Minus(const Seven& other) const;

    bool Equals(const Seven& other) const noexcept;
    bool Bigger(const Seven& other) const noexcept;
    bool Smaller(const Seven& other) const noexcept;

    void Swap(Seven& other);


private:
    size_t size_;
    size_t capacity_;
    unsigned char* data_;

};


namespace std {
    // NOLINTNEXTLINE
    void swap(Seven& first, Seven& second) {
        first.Swap(second);
    }
}
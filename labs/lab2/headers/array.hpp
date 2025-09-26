#pragma once

#include <initializer_list>
#include <string>

namespace Array {
class Array {
public:
    Array();
    Array(std::size_t size);
    Array(std::size_t size, unsigned char ch);
    Array(const std::initializer_list<unsigned char>& il);
    Array(const std::string& str);

    Array(const Array& other);
    Array(Array&& other) noexcept;
    virtual ~Array() noexcept;

    std::size_t Size() const noexcept;
    std::size_t Capacity() const noexcept;

    inline unsigned char& Get(std::size_t i) noexcept;
    inline unsigned char Get(std::size_t i) const noexcept;
    void PushBack(unsigned char ch);
    void Reserve(std::size_t size);

    bool Equals(const Array& other) const noexcept;


private:
    std::size_t _capacity = 0;
    std::size_t _size = 0;
    unsigned char* _data = nullptr;

private:
    inline void CheckCapacity(std::size_t size); 
};
}
#include <string>
#include <vector>


namespace {
    inline bool IsNumber(char ch) {
        return '0' <= ch && ch <= '9';
    }
}

std::vector<int> GetNumbersFromString(const std::string& text) noexcept {
    bool did_number_end = true;
    std::vector<int> numbers;
    int current_number = 0;

    for (char ch: text) {
        if (IsNumber(ch)) {
            current_number = 10 * current_number + ch - '0';
            did_number_end = false;
        } else if (!did_number_end){
            did_number_end = true;
            numbers.push_back(current_number);
            current_number = 0;
        }
    }

    if (!did_number_end) {
        numbers.push_back(current_number);
    }
    return numbers;
}
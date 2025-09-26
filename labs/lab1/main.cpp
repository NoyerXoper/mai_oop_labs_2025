#include <iostream>
#include "filter_text.hpp"


int main() {
    std::string text;
    std::cout << "Enter a string containing only lettets and numbers:\n";
    std::cin >> text;

    std::vector<int> numbers = GetNumbersFromString(text);
    
    std::cout << "numbers in your text:\n";

    for (int num: numbers) {
        std::cout << num << "\n";
    }

    return 0;

}
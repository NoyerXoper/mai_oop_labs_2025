#include <iostream>
#include <string>
#include "seven.hpp"


int main() {
    std::string str;
    std::cin >> str;
    Seven s(str);

    std::cout << "Current number: " << s;

}
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "filter_text.cpp"

TEST(FilterTextTest, BasicTest) {
    std::string text = "Hello 25, World7w09_hello2\n";
    std::vector<int> result = GetNumbersFromString(text);
    ASSERT_EQ(result, std::vector<int>({25, 7, 9, 2}));
}

TEST(FilterTextTest, EmptyStringTest) {
    std::string text;
    std::vector<int> result = GetNumbersFromString(text);
    ASSERT_TRUE(result.empty());
}

TEST(FilterTextTest, DigitStringTest) {
    std::string text = "1234567";
    std::vector<int> result = GetNumbersFromString(text);
    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(result.front(), 1234567);
}


TEST(FilterTextTest, NoDigitsIntegerStringTest) {
    std::string text = "Hello, World, I'm a bad programmer"; 
    std::vector<int> result = GetNumbersFromString(text);
    ASSERT_TRUE(result.empty());
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



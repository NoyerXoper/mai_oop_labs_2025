#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "filter_text.cpp"

TEST(IntegerFilterTextTest, BasicIntegerTest) {
    std::string text = "Hello 25, World7w09_hello2\n";
    std::vector<int> result = GetNumbersFromString<int>(text);
    ASSERT_EQ(result, std::vector<int>({25, 7, 9, 2}));
}

TEST(IntegerFilterTextTest, IntegerEmptyStringTest) {
    std::string text;
    std::vector<int> result = GetNumbersFromString<int>(text);
    ASSERT_TRUE(result.empty());
}

TEST(IntegerFilterTextTest, IntegerDigitStringTest) {
    std::string text = "1234567";
    std::vector<int> result = GetNumbersFromString<int>(text);
    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(result.front(), 1234567);
}


TEST(IntegerFilterTextTest, NoDigitsIntegerStringTest) {
    std::string text = "Hello, World, I'm a bad programmer"; 
    std::vector<int> result = GetNumbersFromString<int>(text);
    ASSERT_TRUE(result.empty());
}

TEST(LongFilterTextTest, BasicLongTest) {
    std::string text = "Hello 25, World7w09_hello";
    std::vector<long> result = GetNumbersFromString<long>(text);
    ASSERT_EQ(result, std::vector<long>({25l, 7l, 9l}));
}

TEST(LongFilterTextTest, IntegerEmptyStringTest) {
    std::string text;
    std::vector<long> result = GetNumbersFromString<long>(text);
    ASSERT_TRUE(result.empty());
}

TEST(LongFilterTextTest, IntegerDigitStringTest) {
    std::string text = "1234567891011";
    std::vector<long> result = GetNumbersFromString<long>(text);
    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(result.front(), 1234567891011L);
}


TEST(LongFilterTextTest, NoDigitsIntegerStringTest) {
    std::string text = "Hello, World, I'm a bad programmer"; 
    std::vector<long> result = GetNumbersFromString<long>(text);
    ASSERT_TRUE(result.empty());
}

TEST(BoolFilterTextTest, BasicBoolTest) {
    std::string text = "111 and also 0, so basically 110"; 
    std::vector<bool> result = GetNumbersFromString<bool>(text);
    ASSERT_EQ(result, std::vector<bool>({true, false, true}));
}

TEST(StringFilterTextTest, BasicStringTest) {
    std::string text = "Hello 25, World7w09_hello";
    std::vector<std::string> result = GetNumbersFromString<std::string>(text);
    ASSERT_EQ(result, std::vector<std::string>({"25", "7", "09"}));
}

TEST(StringFilterTextTest, StringEmptyStringTest) {
    std::string text;
    std::vector<std::string> result = GetNumbersFromString<std::string>(text);
    ASSERT_TRUE(result.empty());
}

TEST(StringFilterTextTest, StringDigitStringTest) {
    std::string text = "123456789101112131415161718192021222324252627282930313233";
    std::vector<std::string> result = GetNumbersFromString<std::string>(text);
    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(result.front(), text);
}


TEST(StringFilterTextTest, NoDigitsStringStringTest) {
    std::string text = "Hello, World, I'm a bad programmer"; 
    std::vector<std::string> result = GetNumbersFromString<std::string>(text);
    ASSERT_TRUE(result.empty());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



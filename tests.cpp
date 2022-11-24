#include "lib.h"

#include "gtest/gtest.h"

void TestSplit(
        const std::string& input_string,
        const char divider,
        const std::vector<std::string>& expected
        )
{
    std::vector<std::string> result;
    result = split(input_string, divider);
    ASSERT_EQ(result, expected);
}
void TestSort(
        const ip_table& input,
        const ip_table& expected
)
{
    ip_table result = {input};
    desc_sort(result);
    ASSERT_EQ(result, expected);
}

TEST(split_test, test1)
{
    const std::string& input_string = {"192.168.0.1"};
    const char divider = {'.'};
    const std::vector<std::string> expected = {"192", "168", "0", "1"};
    TestSplit(input_string, divider, expected);
}
TEST(split_test, test2)
{
    const std::string& input_string = {".."};
    const char divider = {'.'};
    const std::vector<std::string> expected = {"", "", ""};
    TestSplit(input_string, divider, expected);
}
TEST(split_test, test3)
{
    const std::string& input_string = {""};
    const char divider = {'.'};
    const std::vector<std::string> expected = {""};
    TestSplit(input_string, divider, expected);
}
TEST(sort_test, test1)
{
    const ip_table input =
            {
                    {68,46,218,208},
                    {185,46,85,78},
                    {185,46,86,131},
                    {49,251,197,23},
                    {185,46,85,204},
                    {185,46,86,22}
            };
    const ip_table expected =
            {
                    {185,46,86,131},
                    {185,46,86,22},
                    {185,46,85,204},
                    {185,46,85,78},
                    {68,46,218,208},
                    {49,251,197,23}
            };
    TestSort(input, expected);
}
TEST(filter_test, test1)
{
    const ip_table input =
            {
                    {185,46,86,131},
                    {185,46,86,22},
                    {185,46,85,204},
                    {185,46,85,78},
                    {68,46,218,208},
                    {49,251,197,23}
            };
    const ip_table expected =
            {
                    {185,46,86,131},
                    {185,46,86,22},
                    {185,46,85,204},
                    {185,46,85,78}
            };
    ip_table result;
    result = filter(input, 185);
    ASSERT_EQ(result, expected);
}
TEST(filter_test, test2)
{
    const ip_table input =
            {
                    {185,46,86,131},
                    {185,46,86,22},
                    {185,46,85,204},
                    {185,46,85,78},
                    {68,46,218,208},
                    {49,251,197,23}
            };
    const ip_table expected =
            {
                    {185,46,86,131},
                    {185,46,86,22}
            };
    ip_table result;
    result = filter(input, -1, 46, 86);
    ASSERT_EQ(result, expected);
}
TEST(filter_test, test3)
{
    const ip_table input =
            {
                    {185,46,86,131},
                    {185,46,86,22},
                    {185,46,85,204},
                    {185,46,85,78},
                    {68,46,218,208},
                    {49,251,197,23}
            };
    const ip_table expected =
            {
                    {49,251,197,23}
            };
    ip_table result;
    result = filter(input, -1, -1, -1, 23);
    ASSERT_EQ(result, expected);
}
TEST(filter_any_test, test1)
{
    const ip_table input =
            {
                    {185,46,86,131},
                    {185,46,86,22},
                    {185,46,85,204},
                    {185,46,85,78},
                    {46,70,29,76},
                    {46,55,46,86},
                    {46,49,43,86},
                    {39,46,86,85}
            };
    const ip_table expected =
            {
                    {185,46,86,131},
                    {185,46,86,22},
                    {46,55,46,86},
                    {46,49,43,86},
                    {39,46,86,85}
            };
    ip_table result;
    result = filter_any(input, 86);
    ASSERT_EQ(result, expected);
}
TEST(filter_any_test, test2) {
    const ip_table input =
            {
                    {185, 46, 86, 131},
                    {185, 46, 86, 22},
                    {185, 46, 85, 204},
                    {185, 46, 85, 78},
                    {46,  70, 29, 76},
                    {46,  55, 46, 86},
                    {46,  49, 43, 86},
                    {39,  46, 86, 85}
            };
    const ip_table expected =
            {
                    {185, 46, 85, 204},
                    {185, 46, 85, 78},
                    {39,  46, 86, 85}
            };
    ip_table result;
    result = filter_any(input, 46, 85);
    ASSERT_EQ(result, expected);
}
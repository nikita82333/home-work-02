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
        const std::vector<std::vector<std::string>>& input,
        const std::vector<std::vector<std::string>>& expected
)
{
    std::vector<std::vector<std::string>> result = {input};
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
    const std::vector<std::vector<std::string>> input =
            {
                    {"68","46","218","208"},
                    {"185","46","85","78"},
                    {"185","46","86","131"},
                    {"49","251","197","23"},
                    {"185","46","85","204"},
                    {"185","46","86","22"}
            };
    const std::vector<std::vector<std::string>> expected =
            {
                    {"185","46","86","131"},
                    {"185","46","86","22"},
                    {"185","46","85","204"},
                    {"185","46","85","78"},
                    {"68","46","218","208"},
                    {"49","251","197","23"}
            };
    TestSort(input, expected);
}
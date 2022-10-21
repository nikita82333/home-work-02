#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
#include <utility>

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string &str, char d);

// (1.2.1.1, 1.10.1.1) -> false
bool compare_ip(const std::vector<std::string>& ip_a, const std::vector<std::string>& ip_b);

//descending sort
void desc_sort(std::vector<std::vector<std::string>>& ip_pool);

//filter
template<typename... T>
std::vector<std::vector<std::string>> filter(const std::vector<std::vector<std::string>>& ip_pool, T... args)
{
    constexpr size_t MAX_ARGS_NUMBER = 4;
    std::vector<int> values;
    std::vector<std::vector<std::string>> result;
    for (auto&& arg : std::initializer_list<int>{args...}) {
        values.push_back(arg);
    }
    for (const auto& ip : ip_pool) {
        bool condition = true;
        size_t i_args = 0;
        for (auto value : values) {
            if (value >= 0 && value <= 255 && i_args < MAX_ARGS_NUMBER) {
                condition &= (value == std::stoi(ip.at(i_args)));
            }
            ++i_args;
        }
        if (condition) {
            result.template emplace_back(ip);
        }
    }
    return result;
}

//filter_any
template<typename... T>
std::vector<std::vector<std::string>> filter_any(const std::vector<std::vector<std::string>>& ip_pool, T... args)
{
    std::vector<int> values;
    std::vector<std::vector<std::string>> result;
    for (auto&& arg : std::initializer_list<int>{args...}) {
        values.push_back(arg);
    }
    for (const auto& ip : ip_pool) {
        bool condition = true;
        for (auto value : values) {
            if (value >= 0 && value <= 255) {
                bool condition_any = false;
                for (const auto& ip_part : ip) {
                    if (value == std::stoi(ip_part)) {
                        condition_any = true;
                        break;
                    }
                }
                condition &= condition_any;
            }
        }
        if (condition) {
            result.template emplace_back(ip);
        }
    }
    return result;
}

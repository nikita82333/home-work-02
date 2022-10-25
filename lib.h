#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <initializer_list>
#include <utility>

using ip_table_int = std::vector<std::array<int, 4>>;
using ip_table_str = std::vector<std::vector<std::string>>;

//converting an ip pool from a string to an integer representation
ip_table_int converter(const ip_table_str& ip_pool);

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string &str, char d);

//descending sort
void desc_sort(ip_table_int& ip_pool);

//filter
template<typename... T>
ip_table_int filter(const ip_table_int& ip_pool, T... args)
{
    constexpr size_t MAX_ARGS_NUMBER = 4;
    std::vector<int> values;
    ip_table_int result;
    for (auto&& arg : std::initializer_list<int>{args...}) {
        values.push_back(arg);
    }
    for (const auto& ip : ip_pool) {
        bool condition = true;
        size_t i_args = 0;
        for (auto value : values) {
            if (value >= 0 && value <= 255 && i_args < MAX_ARGS_NUMBER) {
                condition &= (value == ip.at(i_args));
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
ip_table_int filter_any(const ip_table_int& ip_pool, T... args)
{
    std::vector<int> values;
    ip_table_int result;
    for (auto&& arg : std::initializer_list<int>{args...}) {
        values.push_back(arg);
    }
    for (const auto& ip : ip_pool) {
        bool condition = true;
        for (auto value : values) {
            if (value >= 0 && value <= 255) {
                bool condition_any = false;
                for (const auto& ip_part : ip) {
                    if (value == ip_part) {
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

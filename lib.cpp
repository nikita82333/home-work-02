#include <algorithm>

#include "lib.h"

ip_table_int converter(const ip_table_str& ip_pool) {
    ip_table_int ip_pool_int;
    for (const auto& ip : ip_pool) {
        std::array<int, 4> ip_int {};
        for (std::size_t i = 0; i < 4; ++i) {
            ip_int.at(i) = std::stoi(ip.at(i));
        }
        ip_pool_int.emplace_back(ip_int);
    }
    return ip_pool_int;
}

std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while (stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

void desc_sort(ip_table_int& ip_pool)
{
    auto compare_ip = [](const auto& ip_a, const auto& ip_b){
        return std::lexicographical_compare(ip_a.begin(), ip_a.end(), ip_b.begin(), ip_b.end(),
                                            std::greater<>());
    };

    std::sort(ip_pool.begin(), ip_pool.end(), compare_ip);
}


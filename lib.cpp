#include <algorithm>

#include "lib.h"

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

void desc_sort(ip_table& ip_pool)
{
    auto compare_ip = [](const auto& ip_a, const auto& ip_b){
        return std::lexicographical_compare(ip_a.begin(), ip_a.end(), ip_b.begin(), ip_b.end(),
                                            std::greater<>());
    };

    std::sort(ip_pool.begin(), ip_pool.end(), compare_ip);
}


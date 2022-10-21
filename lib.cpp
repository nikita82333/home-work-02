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

bool compare_ip(const std::vector<std::string>& ip_a, const std::vector<std::string>& ip_b)
{
    return std::lexicographical_compare(ip_a.begin(), ip_a.end(), ip_b.begin(), ip_b.end(),
                                        [](const auto& a, const auto& b){
                                            return std::stoi(a) > std::stoi(b);
                                        });
}

void desc_sort(std::vector<std::vector<std::string>>& ip_pool)
{
    /*
    * closure (as an option)

        auto compare_ip = [](const auto& ip_a, const auto& ip_b){
            return std::lexicographical_compare(ip_a.begin(), ip_a.end(), ip_b.begin(), ip_b.end(),
                                                [](const auto& a, const auto& b){
                                                    return std::stoi(a) > std::stoi(b);
                                                });
        };
    */
    std::sort(ip_pool.begin(), ip_pool.end(), compare_ip);
}


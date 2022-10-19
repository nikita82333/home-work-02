#pragma once

#include <string>
#include <vector>

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

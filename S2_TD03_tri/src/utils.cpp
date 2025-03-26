#include "utils.hpp"

bool is_sorted(std::vector<int> const& vec) {
    return std::is_sorted(vec.begin(), vec.end());
}
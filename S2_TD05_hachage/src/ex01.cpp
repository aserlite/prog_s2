#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cstdlib>
#include <ctime>  

size_t folding_string_hash_sum(std::string const& s, size_t max) {
    size_t hash {0};
    for (char c : s) {
        hash += static_cast<size_t>(c);
        hash %= max;
    }
    return hash;
}

size_t folding_string_ordered_hash(std::string const& s, size_t max) {
    size_t hash {0};
    for (size_t i = 0; i < s.size(); ++i) {
        hash += static_cast<size_t>(s[i]) * (i + 1);
        hash %= max;
    }
    return hash;
}

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m) {
    size_t hash {0};
    size_t power {1};
    for (char c : s) {
        hash = (hash + (static_cast<size_t>(c) * power) % m) % m;
        power = (power * p) % m;
    }
    return hash;
}

int main() {
    std::string test = "abc";
    size_t max = 1024;

    std::cout << "folding_string_hash_sum: " << folding_string_hash_sum(test, max) << std::endl;
    std::cout << "folding_string_ordered_hash: " << folding_string_ordered_hash(test, max) << std::endl;
    size_t p = 31;
    size_t m = 1024; 
    std::cout << "polynomial_rolling_hash: " << polynomial_rolling_hash(test, p, m) << std::endl;

    return 0;
}
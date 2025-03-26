#include <vector>
#include <algorithm>
#include <iostream>

int search(const std::vector<int>& vec, int value) {
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (vec[middle] == value) {
            return middle;
        }

        if (vec[middle] < value) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }

    return -1;
}

int main() {
    std::vector<int> randomvec(1000);
    std::generate(randomvec.begin(), randomvec.end(), []() { return rand() % 1000; });
    std::sort(randomvec.begin(), randomvec.end());
    int value_to_search = 500;


    std::vector<std::pair<std::vector<int>, int>> test_cases = {
        {{1, 2, 2, 3, 4, 8, 12}, 8},
        {{1, 2, 3, 3, 6, 14, 12, 15}, 15},
        {{2, 2, 3, 4, 5, 8, 12, 15, 16}, 16},
        {{5, 6, 7, 8, 9, 10, 11, 12, 13}, 6},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9}, 10}
    };

    int index = search(randomvec, value_to_search);

    for (const auto& [vec, value] : test_cases) {
        int index = search(vec, value);
        if (index != -1) {
            std::cout << "Value " << value << " trouvé a l'index " << index << std::endl;
        } else {
            std::cout << "Value " << value << " pala" << std::endl;
        }
    }

    if (index != -1) {
        std::cout << "Value " << value_to_search << " trouvé a l'index " << index << std::endl;
    } else {
        std::cout << "Value " << value_to_search << " pala" << std::endl;
    }

    return 0;
}
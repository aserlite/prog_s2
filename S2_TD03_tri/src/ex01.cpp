#include <vector>
#include <algorithm>
#include <iostream>
#include "utils.hpp"

void bubble_sort(std::vector<int> & vec);
void selection_sort(std::vector<int> & vec);

void bubble_sort(std::vector<int> & vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size() - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

void selection_sort(std::vector<int> & vec) {
    for (int i = 0; i < vec.size(); i++) {
        int min = i;
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[j] < vec[min]) {
                min = j;
            }
        }
        std::swap(vec[i], vec[min]);
    }
}

int main() {
    std::vector<int> randomvec(50);
    std::generate(randomvec.begin(), randomvec.end(), []() { return rand() % 100; });
    std::vector<int> vec = randomvec;
    std::vector<int> vec2 = vec;
    bubble_sort(vec);
    selection_sort(vec2);

    std::cout<< "Initial Vector" << std::endl;
    for (int i = 0; i < randomvec.size(); i++) {
        std::cout << randomvec[i] << " ";
    }

    std::cout << std::endl << std::endl << std::endl;
    std::cout<< "Bubble Sort" << std::endl;
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }

    std::cout << std::endl << std::endl << std::endl;
    std::cout<< "Selection Sort" << std::endl;
    for (int i = 0; i < vec2.size(); i++) {
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl << std::endl << std::endl;


    if (!is_sorted(vec) || !is_sorted(vec2)) {
        std::cout << "Failure" << std::endl;
    }else{
        std::cout << "Success" << std::endl;
    }
}

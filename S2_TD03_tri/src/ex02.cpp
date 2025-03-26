#include <vector>
#include <algorithm>
#include <iostream>
#include "utils.hpp"
#include "ScopedTimer.hpp"

size_t quick_sort_partition(std::vector<int> & vec, size_t left, size_t right, size_t const pivot) {
    int pivotValue = vec[pivot];
    std::swap(vec[pivot], vec[right]);
    size_t storeIndex = left;

    for (size_t i = left; i < right; ++i) {
        if (vec[i] < pivotValue) {
            std::swap(vec[i], vec[storeIndex]);
            ++storeIndex;
        }
    }
    std::swap(vec[storeIndex], vec[right]);
    return storeIndex;
}

void quick_sort(std::vector<int> & vec, size_t const left, size_t const right) {
    if (left < right) {
        size_t pivot = left + (right - left) / 2;
        size_t newPivot = quick_sort_partition(vec, left, right, pivot);
        if (newPivot > 0) quick_sort(vec, left, newPivot - 1);
        quick_sort(vec, newPivot + 1, right);
    }
}

void quick_sort(std::vector<int> & vec) {
    ScopedTimer timer("Quick Sort");
    quick_sort(vec, 0, vec.size() - 1);
}

void merge_sort_merge(std::vector<int> & vec, size_t const left, size_t const middle, size_t const right) {
    std::vector<int> leftVec(vec.begin() + left, vec.begin() + middle + 1);
    std::vector<int> rightVec(vec.begin() + middle + 1, vec.begin() + right + 1);

    size_t i = 0, j = 0, k = left;
    while (i < leftVec.size() && j < rightVec.size()) {
        if (leftVec[i] <= rightVec[j]) {
            vec[k++] = leftVec[i++];
        } else {
            vec[k++] = rightVec[j++];
        }
    }

    while (i < leftVec.size()) {
        vec[k++] = leftVec[i++];
    }

    while (j < rightVec.size()) {
        vec[k++] = rightVec[j++];
    }
}

void merge_sort(std::vector<int> & vec, size_t const left, size_t const right) {
    if (left < right) {
        size_t middle = left + (right - left) / 2;
        merge_sort(vec, left, middle);
        merge_sort(vec, middle + 1, right);
        merge_sort_merge(vec, left, middle, right);
    }
}

void merge_sort(std::vector<int> & vec) {
    ScopedTimer timer("Merge ");
    merge_sort(vec, 0, vec.size() - 1);
}

void test(std::vector<int> & vec){
    ScopedTimer timer("Std sort ");
    std::sort(vec.begin(), vec.end());

}

int main() {
    std::vector<int> randomvec(100000);
    std::generate(randomvec.begin(), randomvec.end(), []() { return rand() % 100000000; });

    std::vector<int> vec = randomvec;
    std::vector<int> vec2 = vec;
    std::vector<int> vec3 = vec;
    quick_sort(vec);
    merge_sort(vec2);
    test(vec3);


    if (!is_sorted(vec) || !is_sorted(vec2)) {
        std::cout << "Failure" << std::endl;
    }else{
        std::cout << "Success" << std::endl;
    }

}
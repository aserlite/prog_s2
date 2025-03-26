#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>

size_t first_word_length(std::string const& str) {
    auto const is_space = [](char letter) { return letter == ' '; };

    auto first_letter = std::find_if_not(str.begin(), str.end(), is_space);

    auto end_of_word = std::find_if(first_letter, str.end(), is_space);

    return std::distance(first_letter, end_of_word);
}

std::vector<std::string> split_string(std::string const& str) {
    auto const is_space = [](char letter) { return letter == ' '; };
    std::vector<std::string> words;

    auto it = str.begin();
    while (it != str.end()) {
        it = std::find_if_not(it, str.end(), is_space);

        auto end_of_word = std::find_if(it, str.end(), is_space);

        if (it != str.end()) {
            words.emplace_back(it, end_of_word);
        }

        it = end_of_word;
    }

    return words;
}

int main() {
    std::string phrase = "Ceci est une phrase test";

    size_t length = first_word_length(phrase);
    std::cout << "Longueur du premier mot : " << length << std::endl;

    std::vector<std::string> words = split_string(phrase);
    std::cout << "Mots de la phrase : ";
    for (const auto& word : words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    return 0;
}
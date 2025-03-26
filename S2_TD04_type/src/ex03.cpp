#include <string>
#include <algorithm>
#include <iostream>

bool is_palindrome(std::string const& str) {
    return std::equal(str.begin(), str.end(), str.rbegin());
}

int main() {
    std::string phrase;

    std::cout << "Entrez une phrase : ";
    std::getline(std::cin, phrase);

    if (is_palindrome(phrase)) {
        std::cout << "La phrase est un palindrome." << std::endl;
    } else {
        std::cout << "La phrase n'est pas un palindrome." << std::endl;
    }

    return 0;
}
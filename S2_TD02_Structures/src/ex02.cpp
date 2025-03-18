#include <iostream>
#include <string>
#include <vector>
#include "utils.hpp"

int main() {
    std::string expression;
    std::cout << "Donner une expression en NPI: ";
    std::getline(std::cin, expression);

    std::vector<std::string> words = split_string(expression);
    std::vector<Token> tokens = tokenize(words);

    std::cout << "The result of the expression is: " << npi_evaluate(tokens) << std::endl;

    return 0;
}
#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <cctype>
#include <cmath>

std::vector<std::string> split_string(const std::string& s) {
    std::istringstream in(s);
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>());
}

bool isFloat(const std::string& token) {
    std::istringstream iss(token);
    float f;
    iss >> std::noskipws >> f;
    return iss.eof() && !iss.fail();
}

float npi_evaluate(const std::vector<std::string>& tokens) {
    std::stack<float> stack;

    for (const std::string& token : tokens) {
        if (isFloat(token)) {
            stack.push(std::stof(token));
        } else {
            if (stack.size() < 2) {
                std::cerr << "Error: Invalid expression" << std::endl;
                return 0;
            }
            float operand2 = stack.top(); stack.pop();
            float operand1 = stack.top(); stack.pop();
            if (token == "+") {
                stack.push(operand1 + operand2);
            } else if (token == "-") {
                stack.push(operand1 - operand2);
            } else if (token == "*") {
                stack.push(operand1 * operand2);
            } else if (token == "/") {
                stack.push(operand1 / operand2);
            } else if (token == "^") {
                stack.push(std::pow(operand1, operand2));
            } else {
                std::cerr << "Error: Unknown operator " << token << std::endl;
                return 0;
            }
        }
    }
    if (stack.size() != 1) {
        std::cerr << "Error: Invalid expression" << std::endl;
        return 0;
    }
    return stack.top();
}

int main() {
    std::string expression;
    std::cout << "Donner une expression en NPI: ";
    std::getline(std::cin, expression);

    std::vector<std::string> tokens = split_string(expression);

    std::cout << "The result of the expression is: " << npi_evaluate(tokens) << std::endl;

    return 0;
}
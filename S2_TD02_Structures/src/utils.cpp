#include "utils.hpp"
#include <sstream>
#include <iterator>
#include <cctype>
#include <cmath>
#include <iostream>
#include <stack>

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

Token make_token(float value) {
    return Token{TokenType::OPERAND, value, Operator::ADD}; // Operator::ADD is a placeholder
}

Token make_token(Operator op) {
    return Token{TokenType::OPERATOR, 0.0f, op};
}

std::vector<Token> tokenize(const std::vector<std::string>& words) {
    std::vector<Token> tokens;
    for (const std::string& word : words) {
        if (isFloat(word)) {
            tokens.push_back(make_token(std::stof(word)));
        } else if (word == "+") {
            tokens.push_back(make_token(Operator::ADD));
        } else if (word == "-") {
            tokens.push_back(make_token(Operator::SUB));
        } else if (word == "*") {
            tokens.push_back(make_token(Operator::MUL));
        } else if (word == "/") {
            tokens.push_back(make_token(Operator::DIV));
        } else if (word == "^") {
            tokens.push_back(make_token(Operator::POW));
        } else {
            std::cerr << "Error: Unknown token " << word << std::endl;
        }
    }
    return tokens;
}

float npi_evaluate(const std::vector<Token>& tokens) {
    std::stack<float> stack;

    for (const Token& token : tokens) {
        if (token.type == TokenType::OPERAND) {
            stack.push(token.value);
        } else if (token.type == TokenType::OPERATOR) {
            if (stack.size() < 2) {
                std::cerr << "Error: Invalid expression" << std::endl;
                return 0;
            }
            float operand2 = stack.top(); stack.pop();
            float operand1 = stack.top(); stack.pop();
            switch (token.op) {
                case Operator::ADD:
                    stack.push(operand1 + operand2);
                    break;
                case Operator::SUB:
                    stack.push(operand1 - operand2);
                    break;
                case Operator::MUL:
                    stack.push(operand1 * operand2);
                    break;
                case Operator::DIV:
                    stack.push(operand1 / operand2);
                    break;
                case Operator::POW:
                    stack.push(std::pow(operand1, operand2));
                    break;
            }
        }
    }
    if (stack.size() != 1) {
        std::cerr << "Error: Invalid expression" << std::endl;
        return 0;
    }
    return stack.top();
}
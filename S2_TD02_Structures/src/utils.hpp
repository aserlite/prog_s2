#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

enum class Operator { ADD, SUB, MUL, DIV, POW };
enum class TokenType { OPERATOR, OPERAND };

struct Token {
    TokenType type;
    float value;
    Operator op;
};

std::vector<std::string> split_string(const std::string& s);
bool isFloat(const std::string& token);
Token make_token(float value);
Token make_token(Operator op);
std::vector<Token> tokenize(const std::vector<std::string>& words);
float npi_evaluate(const std::vector<Token>& tokens);

#endif
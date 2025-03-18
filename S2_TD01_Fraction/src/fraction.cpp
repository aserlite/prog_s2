#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

void Fraction::display() {
    std::cout << numerator << "/" << denominator;
}

Fraction Fraction::operator+(Fraction const& other) const {
    return simplify({
        numerator * other.denominator + other.numerator * denominator,
        denominator * other.denominator
    });
}

Fraction Fraction::operator-(Fraction const& other) const {
    return simplify({
        numerator * other.denominator - other.numerator * denominator,
        denominator * other.denominator
    });
}

Fraction Fraction::operator*(Fraction const& other) const {
    return simplify({
        numerator * other.numerator,
        denominator * other.denominator
    });
}

Fraction Fraction::operator/(Fraction const& other) const {
    return simplify({
        numerator * other.denominator,
        denominator * other.numerator
    });
}

Fraction add(Fraction const& f1, Fraction const& f2) {
    return f1 + f2;
}

Fraction sub(Fraction const& f1, Fraction const& f2) {
    return f1 - f2;
}

Fraction mul(Fraction const& f1, Fraction const& f2) {
    return f1 * f2;
}

Fraction div(Fraction const& f1, Fraction const& f2) {
    return f1 / f2;
}

std::ostream& operator<<(std::ostream& os, Fraction const& f) {
    os << f.numerator << "/" << f.denominator;
    return os;
}

bool Fraction::operator==(Fraction const& other) const {
    Fraction simplifiedThis = simplify(*this);
    Fraction simplifiedOther = simplify(other);
    return (simplifiedThis.numerator == simplifiedOther.numerator) &&
           (simplifiedThis.denominator == simplifiedOther.denominator);
}

bool Fraction::operator!=(Fraction const& other) const {
    return !(*this == other);
}
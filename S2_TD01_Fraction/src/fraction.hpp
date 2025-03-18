#pragma once
#include <iostream>

struct Fraction {
    int numerator { 0 };
    int denominator { 1 };

    void display();

    // Surcharge des opérateurs
    Fraction operator+(Fraction const& other) const;
    Fraction operator-(Fraction const& other) const;
    Fraction operator*(Fraction const& other) const;
    Fraction operator/(Fraction const& other) const;

    // Surcharge de l'opérateur <<
    friend std::ostream& operator<<(std::ostream& os, Fraction const& f);

    // Surcharge des opérateurs de comparaison
    bool operator==(Fraction const& other) const;
    bool operator!=(Fraction const& other) const;
};

Fraction add(Fraction const& f1, Fraction const& f2);
Fraction sub(Fraction const& f1, Fraction const& f2);
Fraction mul(Fraction const& f1, Fraction const& f2);
Fraction div(Fraction const& f1, Fraction const& f2);
#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 2 };

    std::cout << "f1 = " << f1 << " f2 = " << f2 << std::endl;

    Fraction f3 { f1 + f2 };

    std::cout << "f1 + f2 = " << f3 << std::endl;
    std::cout << "f1 - f2 = " << (f1 - f2) << std::endl;
    std::cout << "f1 * f2 = " << (f1 * f2) << std::endl;
    std::cout << "f1 / f2 = " << (f1 / f2) << std::endl;
    std::cout << "1/6 + 2/6 = " << (Fraction{1, 6} + Fraction{2, 6}) << std::endl;

    // Comparaison des fractions
    std::cout << "f1 == f2: " << (f1 == f2) << std::endl;
    std::cout << "f1 != f2: " << (f1 != f2) << std::endl;

    return 0;
}
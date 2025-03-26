#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cstdlib>
#include <ctime>  

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::vector<int> numbers(20); 
    std::generate(numbers.begin(), numbers.end(), []() { return std::rand() % 101; });

    std::cout << "Contenu du vecteur : ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    int searchNumber;
    std::cout << "Entrez un nombre à chercher : ";
    std::cin >> searchNumber;

    auto found = std::find(numbers.begin(), numbers.end(), searchNumber);
    if (found != numbers.end()) {
        std::cout << "Le nombre " << searchNumber << " est présent dans le vecteur." << std::endl;
    } else {
        std::cout << "Le nombre " << searchNumber << " n'est pas présent dans le vecteur." << std::endl;
    }

    int countNumber;
    std::cout << "Entrez un nombre pour compter ses occurrences : ";
    std::cin >> countNumber;

    int count = std::count(numbers.begin(), numbers.end(), countNumber);
    std::cout << "Le nombre " << countNumber << " apparaît " << count << " fois dans le vecteur." << std::endl;

    std::sort(numbers.begin(), numbers.end());
    std::cout << "Vecteur trié : "; 
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "La somme des éléments du vecteur est : " << sum << std::endl;

    return 0;
}
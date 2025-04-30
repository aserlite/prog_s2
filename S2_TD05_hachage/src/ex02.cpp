#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <functional>
#include <random>
#include <numeric> // Pour std::accumulate

enum class Insect {
    ClassicBee,
    Ladybug,
    Butterfly,
    Dragonfly,
    Ant,
    Grasshopper,
    Beetle,
    Wasp,
    Caterpillar,
    Spider,
    GuimielBee
};

const std::vector<Insect> insect_values {
    Insect::ClassicBee,
    Insect::Ladybug,
    Insect::Butterfly,
    Insect::Dragonfly,
    Insect::Ant,
    Insect::Grasshopper,
    Insect::Beetle,
    Insect::Wasp,
    Insect::Caterpillar,
    Insect::Spider,
    Insect::GuimielBee
};

const std::unordered_map<Insect, std::string> insect_to_string = {
    {Insect::ClassicBee, "ClassicBee"},
    {Insect::Ladybug, "Ladybug"},
    {Insect::Butterfly, "Butterfly"},
    {Insect::Dragonfly, "Dragonfly"},
    {Insect::Ant, "Ant"},
    {Insect::Grasshopper, "Grasshopper"},
    {Insect::Beetle, "Beetle"},
    {Insect::Wasp, "Wasp"},
    {Insect::Caterpillar, "Caterpillar"},
    {Insect::Spider, "Spider"},
    {Insect::GuimielBee, "GuimielBee"},
};

std::vector<std::pair<Insect, int>> get_insect_observations(
    const size_t number_of_observations,
    std::vector<float> const& insect_probabilities,
    const unsigned int seed = std::random_device{}()) {
    // Create a random engine with a given seed
    std::default_random_engine random_engine(seed);

    auto randInsectIndex { std::bind(std::discrete_distribution<size_t>{insect_probabilities.begin(), insect_probabilities.end()}, random_engine) };
    
    std::vector<std::pair<Insect, int>> observations {};
    observations.reserve(number_of_observations);

    for(size_t i {0}; i < number_of_observations; ++i) {
        size_t const random_insect_index { randInsectIndex() };
        Insect const random_insect { insect_values[random_insect_index] };
        
        //If we have already seen the same insect, increment the count on the last observation
        if (!observations.empty() && observations.back().first == random_insect) {
            observations.back().second++;
        } else {
            observations.push_back({random_insect, 1});
        }
    }

    return observations;
}

std::vector<float> probabilities_from_count(std::vector<int> const& counts) {
    int total_count = std::accumulate(counts.begin(), counts.end(), 0);
    std::vector<float> probabilities;
    probabilities.reserve(counts.size());

    for (int count : counts) {
        probabilities.push_back(static_cast<float>(count) / total_count);
    }

    return probabilities;
}

int main() {
    std::vector<float> initial_probabilities = {0.075, 0.050, 0.100, 0.020, 0.150, 0.200, 0.100, 0.050, 0.075, 0.050, 0.125};

    size_t number_of_observations = 100000;
    auto observations = get_insect_observations(number_of_observations, initial_probabilities, 42);

    std::unordered_map<Insect, int> insect_counts;
    for (const auto& observation : observations) {
        insect_counts[observation.first] += observation.second;
    }

    std::cout << "Insect counts:" << std::endl;
    for (const auto& [insect, count] : insect_counts) {
        std::cout << insect_to_string.at(insect) << ": " << count << std::endl;
    }

    std::vector<int> counts;
    for (const auto& insect : insect_values) {
        counts.push_back(insect_counts[insect]);
    }

    auto observed_probabilities = probabilities_from_count(counts);

    std::cout << "\nProbabilities of observed insects vs expected probabilities" << std::endl;
    for (size_t i = 0; i < insect_values.size(); ++i) {
        const std::string& insect_name = insect_to_string.at(insect_values[i]);
        float observed = observed_probabilities[i];
        float expected = initial_probabilities[i];
        std::cout << insect_name << " : " << observed << " vs " << expected;
        if (std::abs(observed - expected) > 0.01) {
            std::cout << " BAD";
        } else {
            std::cout << " OK";
        }
        std::cout << std::endl;
    }

    return 0;
}
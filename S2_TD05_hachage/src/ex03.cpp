#include <string>
#include <algorithm>
#include <iostream>
#include <functional> 
#include <unordered_map>

enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;

    bool operator==(const Card& other) const {
        return kind == other.kind && value == other.value;
    }
};

struct CardHash {
    size_t operator()(const Card& card) const {
        size_t kind_hash = std::hash<int>()(static_cast<int>(card.kind));
        size_t value_hash = std::hash<int>()(static_cast<int>(card.value));
        return kind_hash ^ (value_hash << 1);
    }
};

int main() {
    std::unordered_map<Card, std::string, CardHash> card_map;
    card_map[{CardKind::Heart, CardValue::Ace}] = "Ace of Hearts";
    card_map[{CardKind::Spade, CardValue::King}] = "King of Spades";
    Card card_to_find = {CardKind::Heart, CardValue::Ace};
    if (card_map.find(card_to_find) != card_map.end()) {
        std::cout << "Found: " << card_map[card_to_find] << std::endl;
    } else {
        std::cout << "Card not found!" << std::endl;
    }

    return 0;
}
#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>
using namespace std;
using ll = long long;

namespace trump {

template <typename Card> using Cards = vector<Card>;
template <typename T> using DeckInitializer = function<Cards<T>()>;

enum class Suits { diamond, club, spade, heart };

const vector<Suits> suits_set{
    Suits::diamond, Suits::club, Suits::spade, Suits::heart};

string suit_str(const Suits &suit) {
  switch (suit) {
  case Suits::diamond:
    return "diamond";
  case Suits::club:
    return "club";
  case Suits::spade:
    return "spade";
  case Suits::heart:
    return "heart";
  }
}

ostream &operator<<(ostream &os, const Suits &suit) {
  os << suit_str(suit);
  return os;
}

class Card {
protected:
  string repr(const vector<string> &args) {
    string res{"Card("};
    for (const auto &s : args) {
      res += s;
      res += ", ";
    }
    res.pop_back();
    res.pop_back();
    return res += ")";
  }

public:
  virtual string to_str() = 0;
};

class OrdinalCard : public Card {
  Suits _suit;
  ll _rank;

public:
  const static ll min_rank = 1;
  const static ll max_rank = 13;

  OrdinalCard(Suits suit, ll rank) : _suit(suit) {
    if (rank < min_rank || max_rank < rank)
      throw invalid_argument("rank must be in [1, 13]");
    _rank = rank;
  }

  Suits suit() {
    return _suit;
  }

  ll rank() {
    return _rank;
  }

  string to_str() override {
    return repr({suit_str(_suit), to_string(_rank)});
  }
};

class BJCard : public OrdinalCard {
  ll _value;

public:
  BJCard(Suits suit, ll rank) : OrdinalCard(suit, rank) {
    if (rank >= 11)
      _value = 10;
    else
      _value = rank;
  }

  ll value() {
    return _value;
  }

  string to_str() override {
    return repr({suit_str(suit()), to_string(rank()), to_string(_value)});
  }
};

Cards<BJCard> BJ_deck_initializer() {
  Cards<BJCard> cards;
  for (auto s : suits_set) {
    for (ll i = BJCard::min_rank; i <= BJCard::max_rank; ++i) {
      cards.push_back(BJCard(s, i));
    }
  }
  return cards;
}

template <typename T> class Deck {
  static_assert(is_base_of_v<Card, T>, "T must be derived from Card.");
  Cards<T> _cards;

public:
  Deck(Cards<T> cards) : _cards(cards){};
  Deck(DeckInitializer<T> f) {
    _cards = f();
  }

  ll size() {
    return _cards.size();
  }

  T draw() {
    if (_cards.size() == 0) throw out_of_range("deck is empty");
    T x = _cards.back();
    _cards.pop_back();
    return x;
  }

  void put(T card) {
    _cards.push_back(card);
  }

  void shuffle() {
    random_shuffle(_cards.begin(), _cards.end());
  }
};
} // namespace trump

int main() {
  using namespace trump;
  Deck<BJCard> BJ_deck{BJ_deck_initializer};
  BJ_deck.shuffle();
  BJCard c1 = BJ_deck.draw();
  cout << c1.to_str() << endl;
  BJCard c2 = BJ_deck.draw();
  cout << c2.to_str() << endl;
  BJCard c3 = BJ_deck.draw();
  cout << c3.to_str() << endl;
}

// Card(spade, 3, 3)
// Card(heart, 10, 10)
// Card(heart, 3, 3)
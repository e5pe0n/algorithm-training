// this version needs dynamic_cast in functions to deal with BJCard.
// I want to refactor that by template, such as Deck<BJCard>.
#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <list>
#include <memory>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>
using namespace std;
using ll = long long;

namespace trump {

enum class Suits;
class _Card;

using Card = shared_ptr<_Card>;

using Cards = list<Card>;

using DeckInitializer = function<Cards()>;

enum class Suits { diamond, club, spade, heart };

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

const vector<Suits> suits_set{
    Suits::diamond, Suits::club, Suits::spade, Suits::heart};

class _Card {
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
  };

public:
  virtual string to_str() = 0;
};

class OrdinalCard : public _Card {
  Suits _suit;
  ll _rank;
  ll _min_rank = 1;
  ll _max_rank = 13;

public:
  OrdinalCard(Suits suit, ll rank) : _suit{suit} {
    if (rank < _min_rank || _max_rank < rank)
      throw invalid_argument{"_rank must be in [1, 13]"};
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
  BJCard(Suits suit, ll rank) : OrdinalCard{suit, rank} {
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

Cards BJ_deck_initializer() {
  Cards cards;
  for (auto s : suits_set) {
    for (ll i = 1; i <= 13; ++i) {
      cards.push_back(make_shared<BJCard>(s, i));
    }
  }
  return cards;
}

class Deck {
  Cards _cards;

public:
  Deck(Cards cards) {}
  Deck(DeckInitializer f) {
    _cards = f();
  }
  Card draw() {
    if (_cards.size() == 0) throw out_of_range{"deck is empty"};
    Card x = _cards.front();
    _cards.pop_front();
    return x;
  }
  void put(Card card) {
    _cards.push_front(card);
  }
  void shuffle() {
    vector<Card> v{_cards.begin(), _cards.end()};
    random_shuffle(v.begin(), v.end());
    _cards = list<Card>(v.begin(), v.end());
  }
  ll size() {
    return _cards.size();
  }
};
} // namespace trump

int main() {
  using namespace trump;
  Deck BJ_deck{BJ_deck_initializer};
  BJ_deck.shuffle();
  Card c1 = BJ_deck.draw();
  cout << c1->to_str() << endl;
  Card c2 = BJ_deck.draw();
  cout << c2->to_str() << endl;
  Card c3 = BJ_deck.draw();
  cout << c3->to_str() << endl;
}

// Card(diamond, 5, 5)
// Card(heart, 13, 10)
// Card(diamond, 12, 10)
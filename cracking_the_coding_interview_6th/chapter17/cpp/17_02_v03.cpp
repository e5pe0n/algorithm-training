// Cracking the Coding Interview p.532
#include <chrono>
#include <random>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using hrc = chrono::high_resolution_clock;

enum class Suit { heart, diamond, spade, clover };

vector<Suit> suits = {Suit::heart, Suit::diamond, Suit::spade, Suit::clover};

string repr(Suit suit) {
  switch (suit) {
  case Suit::heart:
    return "H";
    break;
  case Suit::diamond:
    return "D";
    break;
  case Suit::spade:
    return "S";
    break;
  case Suit::clover:
    return "C";
    break;
  default:
    return "unknown";
  }
}

struct Card {
  ll rank;
  Suit suit;
  string repr() {
    return "(" + to_string(rank) + ", " + ::repr(suit) + ")";
  }
};

void shuffle(vector<Card> &cards) {
  auto seed = hrc::now().time_since_epoch().count();
  default_random_engine generator{seed};
  for (ll i = 1; i < cards.size(); ++i) {
    uniform_int_distribution<ll> distribution(0, i);
    ll x = distribution(generator);
    swap(cards[x], cards[i]);
  }
}

vector<Card> make_deck() {
  vector<Card> deck;
  for (ll i = 1; i <= 13; ++i) {
    for (auto s : suits) {
      deck.push_back(Card{i, s});
    }
  }
  return deck;
}

int main() {
  vector<Card> deck = make_deck();
  shuffle(deck);
  for (ll i = 0; i < 5; ++i) {
    puts(deck[i].repr().c_str());
  }
}
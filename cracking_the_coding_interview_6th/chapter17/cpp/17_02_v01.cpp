#include <chrono>
#include <random>
#include <stdexcept>
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

vector<Card> make_deck() {
  vector<Card> deck;
  for (ll i = 1; i <= 13; ++i) {
    for (auto s : suits) {
      deck.push_back(Card{i, s});
    }
  }
  return deck;
}

void shuffle(vector<Card> &cards) {
  if (cards.size() >= 64)
    throw invalid_argument{"cards size must be less than 64."};
  ll b = 0;
  vector<Card> shuffled;
  auto seed = hrc::now().time_since_epoch().count();
  default_random_engine generator{seed};
  for (ll i = cards.size() - 1; i >= 0; --i) {
    uniform_int_distribution<ll> distribution(0, i);
    ll x = distribution(generator);
    ll cnt = 0;
    for (ll j = 0; j < cards.size(); ++j) {
      if (b & (1 << j)) continue;
      if (cnt == x) {
        shuffled.push_back(cards[j]);
        b |= (1 << j);
        break;
      }
      ++cnt;
    }
  }
  cards = shuffled;
}
int main() {
  vector<Card> deck = make_deck();
  for (ll i = 0; i < 5; ++i) {
    puts(deck[i].repr().c_str());
  }
  puts("");
  shuffle(deck);
  for (ll i = 0; i < 5; ++i) {
    puts(deck[i].repr().c_str());
  }
  puts("");

  deck = make_deck();
  shuffle(deck);
  for (ll i = 0; i < 5; ++i) {
    puts(deck[i].repr().c_str());
  }
}

// (1, H)
// (1, D)
// (1, S)
// (1, C)
// (2, H)

// (12, C)
// (5, C)
// (9, H)
// (11, H)
// (2, C)

// (6, S)
// (6, H)
// (8, C)
// (11, C)
// (5, D)
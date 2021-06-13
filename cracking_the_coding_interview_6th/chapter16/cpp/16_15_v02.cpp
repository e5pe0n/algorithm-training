#include <fstream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

struct Res {
  ll hits = 0, pseudo_hits = 0;
  string repr() {
    return "hits=" + to_string(hits)
           + ", pseudo_hits=" + to_string(pseudo_hits);
  }
};

ll code(char c) {
  switch (c) {
  case 'B':
    return 0;
  case 'G':
    return 1;
  case 'R':
    return 2;
  case 'Y':
    return 3;
  default:
    return -1;
  }
}

const ll MAX_COLOR = 4;

Res estimate(const string &guess, const string &sol) {
  if (guess.size() != sol.size())
    throw invalid_argument{"guess and sol must be the same length."};
  Res res{};
  vector<ll> freq(MAX_COLOR);
  for (ll i = 0; i < guess.size(); ++i) {
    if (guess[i] == sol[i])
      ++res.hits;
    else
      ++freq[code(sol[i])];
  }
  for (ll i = 0; i < guess.size(); ++i) {
    ll c = code(guess[i]);
    if (c >= 0 && freq[c] > 0 && guess[i] != sol[i]) {
      ++res.pseudo_hits;
      --freq[c];
    }
  }
  return res;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  string sol, guess;
  ifs >> sol >> guess;
  Res res = estimate(guess, sol);
  puts(res.repr().c_str());
  puts("");
}

int main() {
  solve("../testcases/16_15/01.txt");
  solve("../testcases/16_15/02.txt");
  solve("../testcases/16_15/03.txt");
  solve("../testcases/16_15/04.txt");
  solve("../testcases/16_15/05.txt");
  solve("../testcases/16_15/06.txt");
}

// # ../testcases/16_15/01.txt
// hits=1, pseudo_hits=1

// # ../testcases/16_15/02.txt
// hits=0, pseudo_hits=4

// # ../testcases/16_15/03.txt
// hits=4, pseudo_hits=0

// # ../testcases/16_15/04.txt
// hits=0, pseudo_hits=0

// # ../testcases/16_15/05.txt
// hits=1, pseudo_hits=1

// # ../testcases/16_15/06.txt
// hits=2, pseudo_hits=2

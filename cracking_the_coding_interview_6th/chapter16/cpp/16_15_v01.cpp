#include <fstream>
#include <map>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

struct Res {
  ll hits = 0, pseudo_hits = 0;
};

Res master_mind(const string &sol, const string &guess) {
  map<char, ll> cnt;
  for (auto c : sol) {
    ++cnt[c];
  }
  Res res{};
  for (auto c : guess) {
    if (cnt[c] > 0) {
      ++res.pseudo_hits;
      --cnt[c];
    }
  }
  for (ll i = 0; i < sol.size(); ++i) {
    if (sol[i] == guess[i]) {
      --res.pseudo_hits;
      ++res.hits;
    }
  }
  return res;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  string sol, guess;
  ifs >> sol >> guess;
  Res res = master_mind(sol, guess);
  printf("hits=%lld, pseudo-hits=%lld\n", res.hits, res.pseudo_hits);
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
// hits=1, pseudo-hits=1

// # ../testcases/16_15/02.txt
// hits=0, pseudo-hits=4

// # ../testcases/16_15/03.txt
// hits=4, pseudo-hits=0

// # ../testcases/16_15/04.txt
// hits=0, pseudo-hits=0

// # ../testcases/16_15/05.txt
// hits=1, pseudo-hits=1

// # ../testcases/16_15/06.txt
// hits=2, pseudo-hits=2

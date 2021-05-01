#include <bitset>
#include <cassert>
#include <fstream>
#include <limits>
#include <string>
using namespace std;
using ll = long long;

ll b2d(string s) {
  if (s.size() == 32 && s[0] == '1') {
    ll t = stoi(s.substr(1, 31), nullptr, 2);
    ll ma = numeric_limits<int>::max();
    return -(ma + 1 - t);
  }
  return stoi(s, nullptr, 2);
}

bool get_bit(ll n, ll i) {
  return (n & (1LL << i)) != 0;
}

ll update_bit(ll n, ll i, bool i_th_bit) {
  ll mask = ~(1LL << i);
  return (n & mask) | (i_th_bit << i);
}

ll update_bits(ll n, ll m, ll start, ll end) {
  for (ll i = start; i <= end; ++i) {
    n = update_bit(n, i, get_bit(m, i - start));
  }
  return n;
}

string d2b(ll n) {
  bitset<32> b(n);
  return b.to_string();
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  string n_s, m_s;
  ll i, j;
  ifs >> n_s >> m_s >> i >> j;
  ll n = b2d(n_s);
  ll m = b2d(m_s);
  ll res = update_bits(n, m, i, j);
  puts(d2b(res).c_str());
  puts("");
}

int main() {
  solve("../testcases/05_01/01.txt");
  solve("../testcases/05_01/02.txt");
  solve("../testcases/05_01/03.txt");
  solve("../testcases/05_01/04.txt");
}

// # ../testcases/05_01/01.txt
// 00000000000000000000010001001100

// # ../testcases/05_01/02.txt
// 11001000101111001001010111010001

// # ../testcases/05_01/03.txt
// 11001000101110101011001001010111

// # ../testcases/05_01/04.txt
// 10010010101110101011010011010001

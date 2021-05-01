// Cracking the Coding Interview p.276
#include <bitset>
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

string d2b(ll n) {
  bitset<32> b(n);
  return b.to_string();
}

ll update_bits(ll n, ll m, ll i, ll j) {
  if (i > j || i < 0 || j >= 32) return 0;
  ll all_ones = ~0LL;
  ll left = all_ones << (j + 1);
  ll right = (1LL << i) - 1;
  ll mask = left | right;
  ll n_cleared = n & mask;
  ll m_shifted = m << i;
  return n_cleared | m_shifted;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  string n_s, m_s;
  ll i, j;
  ifs >> n_s >> m_s >> i >> j;
  ll n = b2d(n_s);
  ll m = b2d(m_s);
  printf("%lld\n", n);
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

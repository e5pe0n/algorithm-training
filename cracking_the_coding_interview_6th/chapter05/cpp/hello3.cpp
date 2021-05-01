#include <bitset>
#include <iostream>
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

int main() {
  // cout << b2d("11001000101110101011010011010001") << endl;
  // cout << d2b(numeric_limits<int>::min()) << endl;
  // int n = 1'000'000'000;
  // cout << d2b(~n) << endl;
  // cout << b2d("11000100011001010011010111111111") << endl;
  // int n = numeric_limits<int>::min();
  // cout << d2b(n) << endl;
  // cout << d2b(~n) << endl;
  // cout << b2d("01111111111111111111111111111111") << endl;
  // int n = -1'000'000'000;
  // cout << d2b(~n) << endl;
  // cout << b2d("11010001111011010110101111011011") << endl;
  // cout << b2d("10111101011111110011101110010111") << endl;
  int n1 = -772969509;
  int n2 = -1115735145;
  cout << (n1 ^ n2) << endl;
  // cout << d2b(1821528140) << endl;
  // int n1 = -772969509;
  // int res = n1 >> 10;
  // cout << res << endl;
  // cout << d2b(res) << endl;
}
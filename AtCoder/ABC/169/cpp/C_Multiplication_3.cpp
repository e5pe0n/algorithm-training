#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A;
string B;

void solve() {
  int b = B[0] - '0';
  int _b = stoi((B.substr(2, 2)));
  ll res = A * b + A * _b / 100;
  printf("%lld\n", res);
}

int main() {
  cin >> A >> B;
  solve();
}
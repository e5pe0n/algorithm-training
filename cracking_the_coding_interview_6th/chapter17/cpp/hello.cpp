#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N = 1'000'000;

int main() {
  ofstream ofs{"counts.txt", ios::app};
  ll sum = 0;
  for (ll i = 0; i <= N; ++i) {
    ll n = i;
    ll cnt = 0;
    while (n > 0) {
      if (n % 10 == 2) ++cnt;
      n /= 10;
    }
    sum += cnt;
    ofs << i << " " << sum << '\n';
  }
}
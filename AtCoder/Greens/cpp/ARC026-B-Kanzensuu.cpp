#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;

vector<ll> divisors() {
  vector<ll> res;
  for (ll i = 1; i * i <= N; ++i) {
    if (N % i == 0) {
      res.push_back(i);
      if (N / i != i) { res.push_back(N / i); }
    }
  }
  return res;
}

int main() {
  cin >> N;
  vector<ll> divs = divisors();
  ll sum = 0;
  for (auto v : divs) {
    if (v != N) sum += v;
  }
  if (sum == N)
    puts("Perfect");
  else if (sum < N)
    puts("Deficient");
  else
    puts("Abundant");
}
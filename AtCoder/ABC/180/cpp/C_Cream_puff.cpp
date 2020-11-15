#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

typedef long long ll;

ll N;

int main() {
  cin >> N;
  vector<ll> vll;
  for (ll i = 1; i * i <= N; ++i) {
    if (N % i == 0) {
      vll.push_back(i);
      if (N / i != i) {
        vll.push_back(N / i);
      }
    }
  }
  sort(vll.begin(), vll.end());
  for (auto v : vll) {
    printf("%lld\n", v);
  }
}
#include <iostream>
#include <map>
#include <math.h>
#include <stdio.h>

#define MAX_N 100'000
#define MOD 998'244'353

typedef long long ll;

using namespace std;

int main() {
  int N;
  cin >> N;
  map<int, int> D;
  bool valid = true;
  for (int i = 0; i < N; ++i) {
    int d;
    cin >> d;
    ++D[d];
    if (i == 0 && d != 0) {
      valid = false;
    }
  }
  if (!valid) {
    printf("0\n");
    return 0;
  }

  int d = 0;
  int _c = 1;
  ll ans = 1;
  for (auto p : D) {
    if (p.first == 0 && p.second > 1) {
      ans = 0;
      break;
    }
    if (p.first != d) {
      ans = 0;
      break;
    }
    ll comb = 1;
    for (int i = 0; i < p.second; ++i) {
      comb = (comb * _c) % MOD;
    }
    ans = (ans * comb) % MOD;
    ++d;
    _c = p.second;
  }
  printf("%lld\n", ans);
}
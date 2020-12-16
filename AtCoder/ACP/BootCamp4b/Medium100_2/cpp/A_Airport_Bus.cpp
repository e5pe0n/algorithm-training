#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N, C, K;
ll T[MAX_N];

void solve() {
  sort(T, T + N);
  ll res = 0;
  ll cnt = 0;
  ll t = 0;
  for (int i = 0; i < N; ++i) {
    if (T[i] > t) {
      ++res;
      cnt = 0;
      t = T[i] + K;
    }
    ++cnt;
    if (cnt > C) {
      ++res;
      cnt = 1;
      t = T[i] + K;
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> C >> K;
  for (int i = 0; i < N; ++i) {
    cin >> T[i];
  }
  solve();
}
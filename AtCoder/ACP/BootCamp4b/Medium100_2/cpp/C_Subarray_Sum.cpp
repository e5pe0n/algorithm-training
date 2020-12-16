#include <bits/stdc++.h>
#define MAX_N 100'000
#define MAX_S 1'000'000'000
using namespace std;
typedef long long ll;

ll N, K, S;

void solve() {
  for (int i = 0; i < N; ++i) {
    ll a = S;
    if (i >= K) {
      a = MAX_S;
      if (S == MAX_S) {
        --a;
      }
    }
    printf("%lld%c", a, i == N - 1 ? '\n' : ' ');
  }
};

int main() {
  cin >> N >> K >> S;
  solve();
}
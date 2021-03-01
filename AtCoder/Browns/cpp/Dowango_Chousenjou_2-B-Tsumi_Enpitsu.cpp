#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N;
ll K[MAX_N - 1];
ll res[MAX_N];

int main() {
  cin >> N;
  for (ll i = 0; i < N - 1; ++i) {
    cin >> K[i];
  }
  res[0] = K[0];
  res[N - 1] = K[N - 2];
  for (ll i = 0; i < N - 2; ++i) {
    res[i + 1] = min(K[i], K[i + 1]);
  }
  for (ll i = 0; i < N; ++i) {
    printf("%lld%c", res[i], i == N - 1 ? '\n' : ' ');
  }
}
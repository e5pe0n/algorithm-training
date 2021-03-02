#include <bits/stdc++.h>
#define MAX_S 1'000'000
#define MAX_N 100'000
#define MAX_Q 100'000
using namespace std;
typedef long long ll;

ll N;
vector<ll> S = vector<ll>(MAX_S + 2);
ll Q;
ll K[MAX_Q];

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    ll s;
    cin >> s;
    ++S[s];
  }
  cin >> Q;
  for (ll i = 0; i < Q; ++i) {
    cin >> K[i];
  }
  N -= S[0];
  S[0] = 0;
  for (ll i = MAX_S + 1; i > 0; --i) {
    S[i - 1] += S[i];
  }
  for (ll i = 0; i <= MAX_S + 1; ++i) {
    S[i] = N - S[i];
  }
  for (ll i = 0; i < Q; ++i) {
    auto it = lower_bound(S.begin(), S.end(), N - K[i]);
    printf("%ld\n", it - S.begin());
  }
}
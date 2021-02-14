#include <bits/stdc++.h>
#define MAX_D 10000
#define MAX_K 100
using namespace std;
typedef long long ll;

ll N, D, K;
ll L[MAX_D], R[MAX_D];
ll S[MAX_K], T[MAX_K];
ll P[MAX_K];
ll res[MAX_K];

int main() {
  cin >> N >> D >> K;
  for (ll i = 0; i < D; ++i) {
    cin >> L[i] >> R[i];
  }
  for (ll i = 0; i < K; ++i) {
    cin >> S[i] >> T[i];
    P[i] = S[i];
  }
  for (ll i = 0; i < D; ++i) {
    for (ll j = 0; j < K; ++j) {
      if (L[i] <= P[j] && P[j] <= R[i]) {
        if (S[j] < T[j] && P[j] < T[j]) {
          P[j] = R[i];
          if (T[j] <= P[j]) res[j] = i + 1;
        } else if (S[j] > T[j] && T[j] < P[j]) {
          P[j] = L[i];
          if (P[j] <= T[j]) res[j] = i + 1;
        }
      }
    }
  }
  for (ll i = 0; i < K; ++i) {
    printf("%lld\n", res[i]);
  }
}

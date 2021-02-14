#include <bits/stdc++.h>
#define MAX_N 10
using namespace std;
typedef long long ll;

ll N, M;
bool D[MAX_N][MAX_N];

int main() {
  cin >> N >> M;
  for (ll i = 0; i < M; ++i) {
    ll A, B;
    cin >> A >> B;
    --A;
    --B;
    D[A][B] = true;
    D[B][A] = true;
  }
  for (ll i = 0; i < N; ++i) {
    set<ll> st;
    for (ll j = 0; j < N; ++j) {
      if (i == j) continue;
      if (D[i][j]) {
        for (ll k = 0; k < N; ++k) {
          if (k == i || k == j) continue;
          if (D[j][k] && !D[k][i]) st.insert(k);
        }
      }
    }
    printf("%ld\n", st.size());
  }
}
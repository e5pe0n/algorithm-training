#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll MAX_N = 800;
const ll MAX_A = 1e9;

ll N, K;
ll A[MAX_N][MAX_N];

int main() {
  cin >> N >> K;
  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < N; ++j) {
      cin >> A[i][j];
    }
  }
}
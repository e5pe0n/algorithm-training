#include <bits/stdc++.h>
#define MAX_N 200'000
#define MAX_M 200'000
#define MAX_Q 200'000
using namespace std;
typedef long long ll;

ll N;
ll X[MAX_N], Y[MAX_N];
ll M;
ll op[MAX_M][2];
ll Q;
ll A[MAX_Q], B[MAX_Q];

ll C[MAX_M];
ll DX[MAX_M], DY[MAX_M];

void solve() {}

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i];
  }
  cin >> M;
  for (ll i = 0; i < M; ++i) {
    cin >> op[i][0];
    if (op[i][0] >= 3) cin >> op[i][1];
  }
  cin >> Q;
  for (ll i = 0; i < Q; ++i) {
    cin >> A[i] >> B[i];
    --A[i];
    --B[i];
  }
  solve();
}
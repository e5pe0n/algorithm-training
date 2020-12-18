#include <bits/stdc++.h>
#define MAX_N 100'000
#define MAX_Q 100'000
using namespace std;
typedef long long ll;

ll N, Q;
string S;
ll L[MAX_Q], R[MAX_Q];
ll sum[MAX_N + 1];

void solve() {
  for (int i = 0; i < N; ++i) {
    sum[i + 1] = sum[i] + (i - 1 >= 0 && S[i - 1] == 'A' && S[i] == 'C');
  }
  for (int i = 0; i < Q; ++i) {
    printf("%lld\n", sum[R[i] + 1] - sum[L[i] + 1]);
  }
}

int main() {
  cin >> N >> Q >> S;
  for (int i = 0; i < Q; ++i) {
    cin >> L[i] >> R[i];
    --L[i];
    --R[i];
  }
  solve();
}
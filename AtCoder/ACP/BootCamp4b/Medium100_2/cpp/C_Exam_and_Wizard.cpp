#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N], B[MAX_N];

void solve() {
  ll res = 0;
  vector<vector<ll>> V;
  ll shortage = 0;
  for (int i = 0; i < N; ++i) {
    V.push_back(vector<ll>{A[i] - B[i], A[i], B[i]});
    if (B[i] - A[i] > 0) {
      shortage += B[i] - A[i];
      ++res;
    }
  }
  if (shortage == 0) {
    printf("0\n");
    return;
  }
  sort(V.begin(), V.end());
  for (int i = N - 1; i >= 0; --i) {
    shortage -= V[i][0];
    ++res;
    if (shortage <= 0) {
      printf("%lld\n", res);
      return;
    }
  }
  printf("-1\n");
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < N; ++i) {
    cin >> B[i];
  }
  solve();
}
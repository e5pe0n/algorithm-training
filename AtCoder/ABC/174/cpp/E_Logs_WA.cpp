#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;
typedef long long ll;

ll N, K;
ll A[MAX_N];
ll C[MAX_N];

void solve() {
  ll t = 0;
  for (int i = 0; i < N; ++i) {
    t += A[i];
  }
  ll k = 0;
  vector<vector<double>> B;
  for (int i = 0; i < N; ++i) {
    B.push_back(vector<double>{(double)A[i] * K / t - A[i] * K / t, (double)i});
    C[i] = A[i] * K / t + 1;
    k += C[i] - 1;
  }
  sort(B.begin(), B.end());
  for (int i = 0; i < N; ++i) {
    printf("%f%c", B[i][0], i == N - 1 ? '\n' : ' ');
  }
  for (int i = 0; i < N; ++i) {
    printf("%lld%c", C[i], i == N - 1 ? '\n' : ' ');
  }
  for (int i = N - 1; i >= 0; --i) {
    if (k >= K) {
      break;
    }
    ++C[(int)B[i][1]];
    ++k;
  }
  for (int i = 0; i < N; ++i) {
    printf("%lld%c", C[i], i == N - 1 ? '\n' : ' ');
  }
  ll res = 0;
  for (int i = 0; i < N; ++i) {
    res = max(res, (ll)ceil((double)A[i] / C[i]));
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}
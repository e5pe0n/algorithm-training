#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

void solve() {
  sort(A, A + N);
  ll res = 0;
  res += A[N - 1];
  int j = N - 2;
  int cnt = 0;
  for (int i = N - 3; i >= 0; --i) {
    res += A[j];
    ++cnt;
    if (cnt % 2 == 0) {
      --j;
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}
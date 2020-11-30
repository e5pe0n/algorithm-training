#include <bits/stdc++.h>
#define MAX_N 100'000
#define THRE 1'000'000'000'000'000'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

void solve() {
  bool zero = false;
  for (int i = 0; i < N; ++i) {
    if (A[i] == 0) {
      zero = true;
      break;
    }
  }
  if (zero) {
    printf("0\n");
    return;
  }
  ll res = 1;
  for (int i = 0; i < N; ++i) {
    if (A[i] <= THRE / res) {
      res *= A[i];
    } else {
      res = -1;
      break;
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
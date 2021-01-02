#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];
ll B[MAX_N];

void solve() {
  for (int i = N; i > 0; --i) {
    int t = 0;
    for (int j = i; j <= N; j += i) {
      t += B[j - 1];
    }
    if (t % 2 != A[i - 1]) {
      B[i - 1] = (B[i - 1] + 1) % 2;
    }
  }
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    cnt += B[i];
  }
  printf("%d\n", cnt);
  if (cnt == 0) {
    return;
  }
  for (int i = 0; i < N; ++i) {
    if (B[i]) {
      printf("%d%c", i + 1, --cnt == 0 ? '\n' : ' ');
    }
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    B[i] = A[i];
  }
  solve();
}
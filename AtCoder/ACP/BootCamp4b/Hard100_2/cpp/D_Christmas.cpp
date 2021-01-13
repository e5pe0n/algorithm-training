#include <bits/stdc++.h>
#define MAX_N 50
using namespace std;
typedef long long ll;

ll N, X;
ll P[MAX_N + 1], L[MAX_N + 1];

void solve() {
  ll i = 0;
  L[0] = 1;
  P[0] = 1;
  for (; i < N; ++i) {
    P[i + 1] = P[i] * 2 + 1;
    L[i + 1] = (2 + 1) + L[i] * 2;
  }
  ll res = 0;
  for (; i >= 0; --i) {
    if (i == 0) {
      ++res;
      break;
    }
    ll left = 0;
    ll right = L[i] - 1;
    ll mid = L[i] / 2;
    if (X == left) {
      break;
    } else if (left < X && X < mid) {
      --X;
    } else if (X == mid) {
      res += P[i - 1] + 1;
      break;
    } else if (mid < X && X < right) {
      res += P[i - 1] + 1;
      X -= mid + 1;
    } else if (X == right) {
      res += P[i];
      break;
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> X;
  --X;
  solve();
}
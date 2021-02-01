#include <bits/stdc++.h>
#define MAX_N 8
using namespace std;
typedef long long ll;

ll N;
ll P[MAX_N], Q[MAX_N];
ll A[MAX_N];

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> P[i];
  }
  for (ll i = 0; i < N; ++i) {
    cin >> Q[i];
  }
  for (ll i = 0; i < N; ++i) {
    A[i] = i + 1;
  }
  ll cnt = 0;
  ll a = 0;
  ll b = 0;
  do {
    ++cnt;
    bool f1 = true;
    bool f2 = true;
    for (ll i = 0; i < N; ++i) {
      if (A[i] != P[i]) f1 = false;
      if (A[i] != Q[i]) f2 = false;
    }
    if (f1) a = cnt;
    if (f2) b = cnt;
  } while (next_permutation(A, A + N));
  printf("%lld\n", abs(a - b));
}
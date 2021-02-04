#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  ll i = 0;
  ll res = 0;
  for (ll j = 0; j < N; ++j) {
    if (i + 1 == A[j]) {
      ++i;
    } else {
      ++res;
    }
  }
  if (i == 0) res = -1;
  printf("%lld\n", res);
}
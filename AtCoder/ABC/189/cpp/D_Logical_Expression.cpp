#include <bits/stdc++.h>
#define MAX_N 60
using namespace std;
typedef long long ll;

ll N;
string S[MAX_N];

void solve() {
  ll res = 1;
  for (ll i = 0; i < N; ++i) {
    if (S[i] == "OR") { res = res + (ll)pow(2, i + 1); }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> S[i];
  }
  solve();
}
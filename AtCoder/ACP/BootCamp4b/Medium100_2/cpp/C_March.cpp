#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

const string T = "MARCH";

ll N;
string S[MAX_N];

void solve() {
  map<char, ll> cnt;
  for (int i = 0; i < N; ++i) {
    ++cnt[S[i][0]];
  }
  vector<int> B{0, 0, 1, 1, 1};
  ll res = 0;
  do {
    ll t = 1;
    for (int i = 0; i < 5; ++i) {
      if (B[i]) {
        t *= cnt[T[i]];
      }
    }
    res += t;
  } while (next_permutation(B.begin(), B.end()));
  printf("%lld\n", res);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> S[i];
  }
  solve();
}
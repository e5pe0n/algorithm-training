#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pls = pair<ll, string>;

const ll MAX_N = 1000;

ll N;
pls TS[MAX_N];

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    string s;
    ll t;
    cin >> s >> t;
    TS[i] = {t, s};
  }
  sort(TS, TS + N);
  cout << TS[N - 2].second << endl;
}
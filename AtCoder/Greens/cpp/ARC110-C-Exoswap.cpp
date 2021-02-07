#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;
typedef long long ll;

ll N;
ll P[MAX_N];
ll B[MAX_N + 1];
bool used[MAX_N];

ll sum(ll i) {
  ll s = 0;
  while (i > 0) {
    s += B[i];
    i -= i & -i;
  }
  return s;
}

void add(ll i, ll diff) {
  while (i <= N) {
    B[i] += diff;
    i += i & -i;
  }
}

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> P[i];
  }
  ll s = 0;
  vector<ll> res(N);
  for (ll i = 0; i < N; ++i) {
    ll t = i - sum(P[i]);
    s += t;
    res[i] = t;
    add(P[i], 1);
  }
  if (s != N - 1) {
    puts("-1");
    return 0;
  }
  vector<ll> res2;
  for (ll i = 0; i < N; ++i) {
    ll t = res[i];
    ll cnt = 0;
    while (t > 0) {
      ll _i = i - cnt++;
      if (used[_i]) {
        puts("-1");
        return 0;
      }
      used[_i] = true;
      res2.push_back(_i);
      --t;
    }
  }
  for (auto v : res2)
    printf("%lld\n", v);
}
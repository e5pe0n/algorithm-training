#include <bits/stdc++.h>
#define MOD 1'000'000'007
#define MAX_N 200'000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
ll A[MAX_N], B[MAX_N];

ll mod_pow(ll x, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res = res * x % MOD;
    }
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}

void solve() {
  ll cnt = 0;
  map<pll, ll> m;
  for (int i = 0; i < N; ++i) {
    if (A[i] == 0 && B[i] == 0) {
      ++cnt;
    } else {
      if (A[i] == 0) {
        ++m[{0LL, 1LL}];
      } else if (B[i] == 0) {
        ++m[{-1LL, 0LL}];
      } else {
        ll gcd = __gcd(abs(A[i]), abs(B[i]));
        if (B[i] > 0) {
          ++m[{A[i] / gcd, B[i] / gcd}];
        } else {
          ++m[{-A[i] / gcd, -B[i] / gcd}];
        }
      }
    }
  }
  vector<vector<ll>> v;
  for (auto p : m) {
    pll _p = p.first;
    v.push_back(vector<ll>{p.second, _p.first, _p.second});
  }
  sort(v.begin(), v.end());
  ofstream ofs("out_sub1_12_cpp.txt");
  ll res = 1;
  for (auto p : m) {
    pll _p = p.first;
    pll _p2;
    if (_p.first > 0) {
      _p2 = {-_p.second, _p.first};
    } else {
      _p2 = {_p.second, -_p.first};
    }
    ll cnt1 = p.second;
    ll cnt2 = m[_p2];
    ofs << "(" << _p.first << ", " << _p.second << ") " << cnt1 << " | (" << _p2.first << ", " << _p2.second
        << ") " << cnt2 << endl;
    res = res * (((mod_pow(2, cnt1) - 1) + (mod_pow(2, cnt2) - 1) + 1) % MOD) % MOD;
    m.erase(_p2);
  }
  printf("%lld\n", (res - 1 + cnt + MOD) % MOD); // exclude a case to choice nothing by res - 1
}

int main() {
  // cin >> N;
  // for (int i = 0; i < N; ++i) {
  //   cin >> A[i] >> B[i];
  // }
  ifstream ifs("../sub1_12.txt");
  ifs >> N;
  for (int i = 0; i < N; ++i) {
    ifs >> A[i] >> B[i];
  }
  solve();
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll A, B, K;
string res;

ll com(ll n, ll k) {
  if (k == 0) return 1;
  if (k < 0) return 0;
  ll res = 1;
  for (ll i = 1; i <= k; ++i) {
    res = res * (n - i + 1) / i;
  }
  return res;
}

void dfs(ll k, ll a, ll b) {
  if (a == 0 && b == 0) return;
  ll case0 = com(a + b - 1, a - 1);
  ll case1 = case0 + com(a + b - 1, b - 1);
  if (k <= case0) {
    res += 'a';
    dfs(k, a - 1, b);
  } else {
    res += 'b';
    dfs(k - case0, a, b - 1);
  }
}

int main() {
  cin >> A >> B >> K;
  dfs(K, A, B);
  cout << res << endl;
}
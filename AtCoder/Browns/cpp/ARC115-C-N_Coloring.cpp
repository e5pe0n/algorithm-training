#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N + 1];

vector<ll> divisors(ll n) {
  vector<ll> res;
  for (ll i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      res.push_back(i);
      if (n / i != i && n / i != n) res.push_back(n / i);
    }
  }
  return res;
}

int main() {
  cin >> N;
  A[1] = 1;
  for (ll i = 2; i <= N; ++i) {
    vector<ll> divs = divisors(i);
    set<ll> st;
    for (auto d : divs)
      st.insert(A[d]);
    A[i] = st.size() + 1;
  }
  for (ll i = 1; i <= N; ++i)
    printf("%lld%c", A[i], i == N ? '\n' : ' ');
}
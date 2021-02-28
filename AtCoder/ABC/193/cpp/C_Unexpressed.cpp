#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;

int main() {
  cin >> N;
  set<ll> st;
  for (ll i = 2; i * i <= N; ++i) {
    ll n = i * i;
    while (n <= N) {
      st.insert(n);
      n *= i;
    }
  }
  printf("%lld\n", N - st.size());
}
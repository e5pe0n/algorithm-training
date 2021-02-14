#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N;

int main() {
  cin >> N;
  set<ll> st;
  for (ll i = 0; i < N; ++i) {
    ll A;
    cin >> A;
    st.insert(A);
  }
  ll res = 0;
  for (auto s : st) {
    if (s % 2 != 0) {
      ++res;
      continue;
    }
    bool f = true;
    while (s % 2 == 0) {
      s /= 2;
      if (st.count(s)) {
        f = false;
        break;
      }
    }
    if (f) ++res;
  }
  printf("%lld\n", res);
}
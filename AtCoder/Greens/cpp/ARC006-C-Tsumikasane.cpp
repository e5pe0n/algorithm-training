#include <bits/stdc++.h>
#define MAX_N 50
using namespace std;
typedef long long ll;

ll N;

int main() {
  cin >> N;
  set<ll> st;
  for (ll i = 0; i < N; ++i) {
    ll w;
    cin >> w;
    auto it = st.lower_bound(w);
    if (it != st.end()) st.erase(it);
    st.insert(w);
  }
  printf("%ld\n", st.size());
}
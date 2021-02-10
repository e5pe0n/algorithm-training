#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

int main() {
  cin >> N;
  set<ll> st;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
    st.insert(A[i]);
  }
  map<ll, ll> mp;
  ll i = 0;
  for (auto v : st) {
    mp[v] = i++;
  }
  for (ll i = 0; i < N; ++i) {
    printf("%lld\n", mp[A[i]]);
  }
}
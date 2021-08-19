#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 100'000;
ll N;
string S[MAX_N];

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> S[i];
  }
  set<string> st;
  for (ll i = 0; i < N; ++i) {
    if (st.find(S[i]) == st.end()) {
      printf("%lld\n", i + 1);
      st.insert(S[i]);
    }
  }
}
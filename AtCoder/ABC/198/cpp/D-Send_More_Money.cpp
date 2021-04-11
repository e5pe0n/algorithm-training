#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const string U = "UNSOLVABLE";

string S1, S2, S3;

int main() {
  cin >> S1 >> S2 >> S3;
  vector<ll> V;
  for (ll i = 0; i < 10; ++i) {
    V.push_back(i);
  }
  set<char> st;
  for (auto c : S1) {
    st.insert(c);
  }
  for (auto c : S2) {
    st.insert(c);
  }
  for (auto c : S3) {
    st.insert(c);
  }
  if (st.size() > 10) {
    puts(U.c_str());
    return 0;
  }
  ll i = 0;
  vector<ll> s1(S1.size()), s2(S2.size()), s3(S3.size());
  for (auto c : st) {
    for (ll j = 0; j < S1.size(); ++j) {
      if (c == S1[j]) s1[j] = i;
    }
    for (ll j = 0; j < S2.size(); ++j) {
      if (c == S2[j]) s2[j] = i;
    }
    for (ll j = 0; j < S3.size(); ++j) {
      if (c == S3[j]) s3[j] = i;
    }
    ++i;
  }
  do {
    vector<ll> _N1, _N2, _N3;
    for (auto n : s1) {
      _N1.push_back(V[n]);
    }
    for (auto n : s2) {
      _N2.push_back(V[n]);
    }
    for (auto n : s3) {
      _N3.push_back(V[n]);
    }
    if (_N1[0] != 0 && _N2[0] != 0 && _N3[0] != 0) {
      ll N1 = 0, N2 = 0, N3 = 0;
      for (auto n : _N1) {
        N1 = N1 * 10 + n;
      }
      for (auto n : _N2) {
        N2 = N2 * 10 + n;
      }
      for (auto n : _N3) {
        N3 = N3 * 10 + n;
      }
      if (N1 + N2 == N3) {
        printf("%lld\n", N1);
        printf("%lld\n", N2);
        printf("%lld\n", N3);
        return 0;
      }
    }
  } while (next_permutation(V.begin(), V.end()));
  puts(U.c_str());
}
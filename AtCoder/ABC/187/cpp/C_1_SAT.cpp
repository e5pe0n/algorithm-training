#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;
typedef long long ll;

ll N;
string S[MAX_N];

void solve() {
  map<string, set<string>> C;
  for (int i = 0; i < N; ++i) {
    if (S[i][0] == '!') {
      C[S[i].substr(1)].insert(S[i]);
    } else {
      C[S[i]].insert(S[i]);
    }
  }
  for (auto p : C) {
    auto st = p.second;
    if (st.size() >= 2) {
      string s = *st.begin();
      if (s[0] == '!') { s = s.substr(1); }
      printf("%s\n", s.c_str());
      return;
    }
  }
  printf("satisfiable\n");
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> S[i];
  }
  solve();
}
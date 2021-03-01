#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
typedef long long ll;

ll N;
string S[MAX_N];

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    S[i] = s;
  }
  sort(S, S + N);
  for (ll i = 0; i < N; ++i) {
    string s = S[i];
    reverse(s.begin(), s.end());
    printf("%s\n", s.c_str());
  }
}
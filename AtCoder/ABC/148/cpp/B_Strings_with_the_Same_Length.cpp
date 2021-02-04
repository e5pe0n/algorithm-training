#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
string S, T;

int main() {
  cin >> N >> S >> T;
  string res;
  for (ll i = 0; i < N; ++i) {
    res += S[i];
    res += T[i];
  }
  printf("%s\n", res.c_str());
}
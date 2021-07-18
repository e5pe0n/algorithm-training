#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N;
string S;

int main() {
  cin >> N >> S;
  for (ll i = 0; i < N; ++i) {
    if (S[i] == '1') {
      if (i % 2 == 0)
        puts("Takahashi");
      else
        puts("Aoki");
      return 0;
    }
  }
}
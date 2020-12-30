#include <bits/stdc++.h>
using namespace std;

string S;

void solve() {
  reverse(S.begin(), S.end());
  int i = 0;
  int N = S.size();
  while (i < N) {
    if (S[i] == 'e' && S.substr(i, 5) == "esare") {
        i += 5;
    } else if (S[i] == 'm' && S.substr(i, 5) == "maerd") {
        i += 5;
    } else if (S[i] == 'r' && S.substr(i, 6) == "resare") {
        i += 6;
    } else if (S[i] == 'r' && S.substr(i, 7) == "remaerd") {
        i += 7;
    } else {
      puts("NO");
      return;
    }
  }
  puts("YES");
}

int main() {
  cin >> S;
  solve();
}
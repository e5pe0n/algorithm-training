#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;

int main() {
  cin >> S;
  bool f = true;
  for (ll i = 0; i < S.size(); ++i) {
    if (i % 2 == 0 && !islower(S[i])) {
      f = false;
      break;
    }
    if (i % 2 != 0 && !isupper(S[i])) {
      f = false;
      break;
    }
  }
  if (f)
    puts("Yes");
  else
    puts("No");
}
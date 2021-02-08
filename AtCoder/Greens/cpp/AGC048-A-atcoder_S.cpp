#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll T;
string S;
const string A = "atcoder";

int main() {
  cin >> T;
  for (ll i = 0; i < T; ++i) {
    cin >> S;
    if (S > A) {
      puts("0");
    } else {
      ll j = 0;
      while (j < S.size() && S[j] == 'a')
        ++j;
      if (j == S.size())
        puts("-1");
      else {
        ll res = j;
        if (S[j] > 't') --res;
        printf("%lld\n", res);
      }
    }
  }
}

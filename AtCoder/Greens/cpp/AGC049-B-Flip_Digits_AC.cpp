#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
string S, T;

int main() {
  cin >> N >> S >> T;
  ll cnt = 0;
  ll res1 = 0;
  ll res2 = 0;
  for (ll i = 0; i < N; ++i) {
    if (T[i] == '1') {
      res2 += i;
      ++cnt;
    }
    if (S[i] == '1') {
      if (cnt > 0) {
        res1 += i;
        --cnt;
      } else {
        res2 += i;
        ++cnt;
      }
    }
  }
  if (cnt > 0)
    puts("-1");
  else
    printf("%lld\n", res1 - res2);
}
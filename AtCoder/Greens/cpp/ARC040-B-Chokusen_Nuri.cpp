#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
typedef long long ll;

ll N, R;
string S;

int main() {
  cin >> N >> R >> S;
  ll last = N - 1;
  while (last >= 0 && S[last] == 'o')
    --last;
  ll i = 0;
  ll res = max(0LL, last - R + 1);
  while (i <= last) {
    if (S[i] == 'o') {
      ++i;
    } else {
      ++res;
      i += R;
    }
  }
  printf("%lld\n", res);
}
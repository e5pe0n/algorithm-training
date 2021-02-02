#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, K;
ll R, S, P;
string T;

int main() {
  cin >> N >> K >> R >> S >> P >> T;
  ll res = 0;
  for (ll i = 0; i < N; ++i) {
    if (T[i] == 'x') continue;
    if (T[i] == 'r') res += P;
    if (T[i] == 's') res += R;
    if (T[i] == 'p') res += S;
    if (i + K < N && T[i + K] == T[i]) T[i + K] = 'x';
  }
  printf("%lld\n", res);
}
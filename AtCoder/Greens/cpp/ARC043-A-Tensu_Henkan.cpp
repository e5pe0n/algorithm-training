#include <bits/stdc++.h>
#define MAX_S 1'000'000'000
using namespace std;
typedef long long ll;

ll N, A, B;

int main() {
  cin >> N >> A >> B;
  ll ma = 0;
  ll mi = MAX_S;
  ll sum = 0;
  for (ll i = 0; i < N; ++i) {
    ll S;
    cin >> S;
    ma = max(ma, S);
    mi = min(mi, S);
    sum += S;
  }
  if (ma - mi == 0) {
    puts("-1");
    return 0;
  }
  double P = (double)B / (ma - mi);
  double Q = (N * A - P * sum) / N;
  printf("%.7f %.7f\n", P, Q);
}
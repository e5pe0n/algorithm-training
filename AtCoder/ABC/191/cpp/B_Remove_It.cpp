#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N, X;

int main() {
  cin >> N >> X;
  vector<ll> res;
  for (ll i = 0; i < N; ++i) {
    ll A;
    cin >> A;
    if (A != X) { res.push_back(A); }
  }
  if (res.size() == 0) {
    puts("");
    return 0;
  }
  for (ll i = 0; i < res.size(); ++i) {
    printf("%lld%c", res[i], i == res.size() - 1 ? '\n' : ' ');
  }
}
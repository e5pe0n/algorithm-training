#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>

typedef long long ll;

using namespace std;

ll N;

int main() {
  cin >> N;
  vector<vector<ll>> V;
  for (int i = 0; i < N; ++i) {
    ll a, b;
    cin >> a >> b;
    V.push_back(vector<ll>{a + b, a, b});
  }
  sort(V.begin(), V.end(),
       [](const vector<ll> &left, const vector<ll> &right) { return left[0] > right[0]; });
  ll ans = 0;
  for (int i = 0; i < N; ++i) {
    if (i % 2 == 0) {
      ans += V[i][1];
    } else {
      ans -= V[i][2];
    }
  }
  printf("%lld\n", ans);
}
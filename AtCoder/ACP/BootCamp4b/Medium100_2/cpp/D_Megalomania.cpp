#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
ll A[MAX_N], B[MAX_N];

void solve() {
  vector<pll> V;
  for (int i = 0; i < N; ++i) {
    V.push_back(pll{B[i], A[i]});
  }
  sort(V.begin(), V.end());
  ll t = 0;
  for (auto v : V) {
    t += v.second;
    if (t > v.first) {
      puts("No");
      return;
    }
  }
  puts("Yes");
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
  }
  solve();
}
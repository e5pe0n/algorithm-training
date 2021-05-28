#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

void solve(ll n) {
  vector<ll> dp(n + 1);
  dp[0] = 1;
  for (ll i = 1; i <= n; ++i) {
    for (ll j = i - 1; j >= i - 3 && j >= 0; --j) {
      dp[i] += dp[j];
    }
  }
  cout << dp[n] << endl;
}

int main() {}
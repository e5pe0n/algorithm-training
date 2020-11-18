#include <iostream>
#include <stdio.h>

#define MAX_S 2000
#define MOD 1'000'000'007

using namespace std;
typedef long long ll;

ll S;
ll dp[MAX_S + 1];

int main() {
  cin >> S;
  dp[0] = 1;
  for (int i = 3; i <= S; ++i) {
    dp[i] = (dp[i - 3] + dp[i - 1]) % MOD;
  }
  printf("%lld\n", dp[S]);
}
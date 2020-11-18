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
  for (int i = 1; i <= S; ++i) {
    for (int j = 0; j <= i - 3; ++j) {
      dp[i] = (dp[i] + dp[j]) % MOD;
    }
  }
  printf("%lld\n", dp[S]);
}
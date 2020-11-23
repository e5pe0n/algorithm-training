#include <bits/stdc++.h>
#define MAX_A 100
using namespace std;

int A, B, C;
double dp[MAX_A + 1][MAX_A + 1][MAX_A + 1];

double _f();
double f();

double f(int a, int b, int c) {
  if (a >= 100 || b >= 100 || c >= 100) {
    return 0;
  }
  int t = a + b + c;
  double res = 0;
  if (dp[a + 1][b][c] == 0) {
    dp[a + 1][b][c] = f(a + 1, b, c);
  }
  res += (dp[a + 1][b][c] + 1) * a / t;
  if (dp[a][b + 1][c] == 0) {
    dp[a][b + 1][c] = f(a, b + 1, c);
  }
  res += (dp[a][b + 1][c] + 1) * b / t;
  if (dp[a][b][c + 1] == 0) {
    dp[a][b][c + 1] = f(a, b, c + 1);
  }
  res += (dp[a][b][c + 1] + 1) * c / t;
  return res;
}

int main() {
  cin >> A >> B >> C;
  printf("%.7f\n", f(A, B, C));
}
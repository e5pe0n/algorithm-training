#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A, B, C, D;

void solve() {
  ll mul_C_B = B / C;
  ll mul_D_B = B / D;
  ll lcm = C * D / __gcd(C, D);
  ll mul_CD_B = B / lcm;
  ll mul_C_A = (A - 1) / C;
  ll mul_D_A = (A - 1) / D;
  ll mul_CD_A = (A - 1) / lcm;
  ll mul_C_B_A = mul_C_B - mul_C_A;
  ll mul_D_B_A = mul_D_B - mul_D_A;
  ll mul_CD_B_A = mul_CD_B - mul_CD_A;
  ll res = (B - A + 1) - (mul_C_B_A + mul_D_B_A - mul_CD_B_A);
  printf("%lld\n", res);
}

int main() {
  cin >> A >> B >> C >> D;
  solve();
}
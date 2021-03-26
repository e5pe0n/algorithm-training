#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M, D;

int main() {
  cin >> N >> M >> D;
  double p = D == 0 ? 1.0 / N : 2.0 * (N - D) / N / N;
  double res = p * (M - 1);
  printf("%.7f\n", res);
}
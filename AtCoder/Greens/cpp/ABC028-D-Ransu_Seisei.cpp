#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, K;

int main() {
  cin >> N >> K;
  double res = (6.0 * (N - K) * (K - 1) + 3.0 * (N - 1) + 1) / N / N / N;
  printf("%.10f\n", res);
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;

int main() {
  cin >> N;
  double res = 0;
  for (ll i = 1; i < N; ++i) {
    res += (double)N / (N - i);
  }
  printf("%.7f\n", res);
}
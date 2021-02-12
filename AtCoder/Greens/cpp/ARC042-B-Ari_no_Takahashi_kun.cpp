#include <bits/stdc++.h>
#define INF 1'000'000'000
#define MAX_N 10
using namespace std;
typedef long long ll;

ll cx, cy;
ll N;
ll X[MAX_N], Y[MAX_N];

int main() {
  cin >> cx >> cy >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i];
  }
  double res = INF;
  for (ll i = 0; i < N; ++i) {
    ll p = abs(X[i] * (Y[(i + 1) % N] - cy) + X[(i + 1) % N] * (cy - Y[i])
               + cx * (Y[i] - Y[(i + 1) % N]));
    double q =
        sqrt(pow(X[i] - X[(i + 1) % N], 2) + pow(Y[i] - Y[(i + 1) % N], 2));
    res = min(res, p / q);
  }
  printf("%.7f\n", res);
}
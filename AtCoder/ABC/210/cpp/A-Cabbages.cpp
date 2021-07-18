#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, A, X, Y;

int main() {
  cin >> N >> A >> X >> Y;
  printf("%lld\n", min(N, A) * X + max(0LL, N - A) * Y);
}
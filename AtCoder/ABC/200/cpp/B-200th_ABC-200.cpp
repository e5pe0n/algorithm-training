#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, K;

void f() {
  while (K--) {
    if (N % 200 == 0)
      N /= 200;
    else
      N = stoll(to_string(N) + "200");
  }
}

int main() {
  cin >> N >> K;
  f();
  printf("%lld\n", N);
}
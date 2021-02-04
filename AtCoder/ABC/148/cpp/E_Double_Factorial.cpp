#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;

int main() {
  cin >> N;
  if (N % 2 != 0) {
    puts("0");
    return 0;
  }
  ll res = 0;
  N /= 10;
  while (N > 0) {
    res += N;
    N /= 5;
  }
  printf("%lld\n", res);
}
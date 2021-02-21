#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll A[] = {0, 1, 2, 3, 4};
  auto cmp_dsc = [](ll &x, ll &y) { return x > y; };
  auto cmp_asc = [](ll &x, ll &y) { return x < y; };
  sort(A, A + 5, cmp_dsc);
  for (ll i = 0; i < 5; ++i) {
    printf("%lld%c", A[i], i == 4 ? '\n' : ' ');
  }
  sort(A, A + 5, cmp_asc);
  for (ll i = 0; i < 5; ++i) {
    printf("%lld%c", A[i], i == 4 ? '\n' : ' ');
  }
}
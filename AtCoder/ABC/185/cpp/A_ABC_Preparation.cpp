#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A[4];

int main() {
  for (int i = 0; i < 4; ++i) {
    cin >> A[i];
  }
  ll res = *min_element(A, A + 4);
  printf("%lld\n", res);
}
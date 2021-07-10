#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll A, B;

int main() {
  cin >> A >> B;
  printf("%lld\n", max(B - A + 1, 0LL));
}
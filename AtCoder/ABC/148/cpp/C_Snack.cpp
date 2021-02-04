#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A, B;

int main() {
  cin >> A >> B;
  ll res = A / __gcd(A, B) * B;
  printf("%lld\n", res);
}
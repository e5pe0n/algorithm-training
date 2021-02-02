#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A, B, K;

int main() {
  cin >> A >> B >> K;
  printf("%lld %lld\n", max(0LL, A - K), max(0LL, B + min(0LL, A - K)));
}
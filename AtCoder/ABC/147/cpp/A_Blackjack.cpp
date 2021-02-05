#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll A;
  ll sum = 0;
  for (ll i = 0; i < 3; ++i) {
    cin >> A;
    sum += A;
  }
  if (sum <= 21)
    puts("win");
  else
    puts("bust");
}
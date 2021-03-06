#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A, B;

int main() {
  cin >> A >> B;
  A += B;
  ll res;
  if (15 <= A && 8 <= B)
    res = 1;
  else if (10 <= A && 3 <= B)
    res = 2;
  else if (3 <= A)
    res = 3;
  else
    res = 4;
  printf("%lld\n", res);
}
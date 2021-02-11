#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll L[3];

int main() {
  for (ll i = 0; i < 3; ++i) {
    cin >> L[i];
  }
  sort(L, L + 3);
  ll R = L[0] + L[1] + L[2];
  ll r;
  if (L[0] + L[1] >= L[2])
    r = 0;
  else
    r = L[2] - L[0] - L[1];
  printf("%.7f\n", M_PI * (R * R - r * r));
}
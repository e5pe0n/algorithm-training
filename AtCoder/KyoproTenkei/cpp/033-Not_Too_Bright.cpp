#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_H = 100;
const ll MAX_W = 100;
ll H, W;

int main() {
  cin >> H >> W;
  ll res;
  if (H == 1 || W == 1)
    res = H * W;
  else
    res = ((H + 1) / 2) * ((W + 1) / 2);
  printf("%lld\n", res);
}
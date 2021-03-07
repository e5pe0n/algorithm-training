#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll H, W;

int main() {
  cin >> H >> W;
  if (H % 3 == 0 || W % 3 == 0) {
    puts("0");
    return 0;
  }
  ll res = H * ((W + 3 - 1) / 3) - H * (W / 3);
  res = min(res, ((H + 3 - 1) / 3) * W - (H / 3) * W);
  for (ll j = 1; j < W; ++j) {
    ll left = H * j;
    ll top = (H + 2 - 1) / 2 * (W - j);
    ll btm = H / 2 * (W - j);
    res = min(res, max({left, top, btm}) - min({left, top, btm}));
  }
  for (ll i = 1; i < H; ++i) {
    ll top = W * i;
    ll left = (H - i) * ((W + 2 - 1) / 2);
    ll right = (H - i) * (W / 2);
    res = min(res, max({top, left, right}) - min({top, left, right}));
  }
  printf("%lld\n", res);
}
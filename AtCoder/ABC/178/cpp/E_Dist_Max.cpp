#include <algorithm>
#include <iostream>
#include <stdio.h>

#define MAX_N 200'000
#define MAX_Z 1'000'000'000
#define MAX_W 1'000'000'000

using namespace std;
typedef long long ll;

ll N;

int main() {
  cin >> N;
  ll max_z = -MAX_Z;
  ll min_z = MAX_Z * 2;
  ll max_w = -MAX_W;
  ll min_w = MAX_W * 2;
  for (int i = 0; i < N; ++i) {
    ll x, y, z, w;
    cin >> x >> y;
    z = x + y;
    w = x - y;
    max_z = max(max_z, z);
    min_z = min(min_z, z);
    max_w = max(max_w, w);
    min_w = min(min_w, w);
  }
  ll res = max(max_z - min_z, max_w - min_w);
  printf("%lld\n", res);
}
#include <bits/stdc++.h>
#define MAX_H 16
#define MAX_W 16
using namespace std;
typedef long long ll;

ll H, W, A, B;
bool used[MAX_H][MAX_W];

ll dfs(ll i, ll bit, ll a, ll b) {
  if (i == H * W) return 1;
  if (bit & 1 << i) return dfs(i + 1, bit, a, b);
  ll res = 0;
  if (b) res += dfs(i + 1, bit | 1 << i, a, b - 1);
  if (a) {
    if (i % W != W - 1 && ~bit && 1 << (i + 1))
      res += dfs(i + 1, bit | 1 << i | 1 << (i + 1), a - 1, b);
    if (i + W < H * W) res += dfs(i + 1, bit | 1 << i | 1 << (i + W), a - 1, b);
  }
  return res;
}

int main() {
  cin >> H >> W >> A >> B;
  ll res = dfs(0, 0, A, B);
  printf("%lld\n", res);
}
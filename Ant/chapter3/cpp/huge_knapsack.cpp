#include <algorithm>
#include <fstream>
#include <stdio.h>
#include <utility>

#define MAX_N 40
#define INF 1'000'000'000'000'000'000

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int n;
ll w[MAX_N], v[MAX_N];
ll W;
pll ps[1 << (MAX_N / 2)];

int main() {
  ifstream ifs("../testset/huge_knapsack/test1.txt");
  ifs >> n >> W;
  for (int i = 0; i < n; ++i) {
    ifs >> w[i];
  }
  for (int i = 0; i < n; ++i) {
    ifs >> v[i];
  }
  int n2 = n / 2;
  for (int i = 0; i < 1 << n2; ++i) {
    ll sw = 0;
    ll sv = 0;
    for (int j = 0; j < n2; ++j) {
      if (i >> j & 1) {
        sw += w[j];
        sv += v[j];
      }
    }
    ps[i] = pll(sw, sv);
  }
  sort(ps, ps + (1 << n2));
  int m = 1; // num of sorted els = last idx of sorted els + 1 = idx to insert a new el
  // sorted els satisfy ps[i].w <= ps[i + 1].w and ps[i].v < ps[i + 1].v
  for (int i = 1; i < 1 << n2; ++i) {
    if (ps[m - 1].second < ps[i].second) {
      ps[m++] = ps[i];
    }
  }
  ll res = 0;
  for (int i = 0; i < 1 << (n - n2); ++i) {
    ll sw = 0;
    ll sv = 0;
    for (int j = 0; j < n - n2; ++j) {
      if (i >> j & 1) {
        sw += w[n2 + j];
        sv += v[n2 + j];
      }
    }
    if (sw <= W) {
      ll tv = (lower_bound(ps, ps + m, pll(W - sw, INF)) - 1)->second;
      res = max(res, sv + tv);
    }
  }
  printf("%lld\n", res);
}
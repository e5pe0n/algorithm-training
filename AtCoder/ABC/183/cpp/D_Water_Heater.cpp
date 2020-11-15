#include <algorithm>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>

#define MAX_N 200'000

using namespace std;

typedef long long ll;

struct X {
  ll s, t, p;
};

ll N, W;
X V[MAX_N];

int main() {
  cin >> N >> W;
  for (int i = 0; i < N; ++i) {
    ll s, t, p;
    cin >> s >> t >> p;
    V[i] = X{s, t - 1, p};
  }
  sort(V, V + N, [](const X &left, const X &right) { return left.s < right.s; });
  int i = 0;
  ll p = 0;
  auto comp = [](const X &left, const X &right) { return left.t > right.t; };
  priority_queue<X, vector<X>, decltype(comp)> q(comp);
  while (i < N) {
    if (q.empty() || V[i].s <= q.top().t) {
      p += V[i].p;
      if (p > W) {
        printf("No\n");
        return 0;
      }
      q.push(V[i++]);
    } else {
      p -= q.top().p;
      q.pop();
    }
  }
  printf("Yes\n");
}
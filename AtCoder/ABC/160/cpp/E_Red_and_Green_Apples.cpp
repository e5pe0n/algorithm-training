#include <bits/stdc++.h>
#define MAX_A 100'000
#define MAX_B 100'000
#define MAX_C 100'000
using namespace std;
typedef long long ll;

int X, Y, A, B, C;
int P[MAX_A], Q[MAX_B], R[MAX_C];

void solve() {
  sort(P, P + A);
  sort(Q, Q + B);
  priority_queue<int, vector<int>, greater<vector<int>::value_type>> pq, qq;
  for (int i = A - 1; i >= A - X; --i) {
    pq.push(P[i]);
  }
  for (int i = B - 1; i >= B - Y; --i) {
    qq.push(Q[i]);
  }
  for (int i = 0; i < C; ++i) {
    int r = R[i];
    int p = pq.top();
    int q = qq.top();
    if (p < q) {
      if (p < r) {
        pq.pop();
        pq.push(r);
      }
    } else {
      if (q < r) {
        qq.pop();
        qq.push(r);
      }
    }
  }
  ll res = 0;
  while (!pq.empty()) {
    res += pq.top();
    pq.pop();
  }
  while (!qq.empty()) {
    res += qq.top();
    qq.pop();
  }
  printf("%lld\n", res);
}

int main() {
  cin >> X >> Y >> A >> B >> C;
  for (int i = 0; i < A; ++i) {
    cin >> P[i];
  }
  for (int i = 0; i < B; ++i) {
    cin >> Q[i];
  }
  for (int i = 0; i < C; ++i) {
    cin >> R[i];
  }
  solve();
}
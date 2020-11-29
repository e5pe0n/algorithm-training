#include <bits/stdc++.h>
#define M 200'000
#define MAX_N 200'000
#define MAX_Q 200'000
using namespace std;
typedef long long ll;

ll N, Q;
ll A[MAX_N], B[MAX_N];
ll C[MAX_Q], D[MAX_Q];

multiset<ll> mv[MAX_N];
multiset<ll> ms;

void solve() {
  for (int i = 0; i < N; ++i) {
    mv[B[i]].insert(A[i]);
  }
  for (int i = 0; i < M; ++i) {
    if (!mv[i].empty()) {
      ms.insert(*mv[i].rbegin());
    }
  }
  for (int i = 0; i < Q; ++i) {
    int c = C[i];
    int d = D[i];
    ms.erase(ms.find(*mv[B[c]].rbegin()));
    mv[B[c]].erase(mv[B[c]].find(A[c]));
    if (!mv[B[c]].empty()) {
      ms.insert(*mv[B[c]].rbegin());
    }
    if (!mv[d].empty()) {
      ms.erase(ms.find(*mv[d].rbegin()));
    }
    mv[d].insert(A[c]);
    ms.insert(*mv[d].rbegin());
    B[c] = d;
    printf("%lld\n", *ms.begin());
  }
}

int main() {
  cin >> N >> Q;
  for (int i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
    --B[i];
  }
  for (int i = 0; i < Q; ++i) {
    cin >> C[i] >> D[i];
    --C[i];
    --D[i];
  }
  solve();
}
#include <bits/stdc++.h>
#define MOD 1'000'000'007
#define MAX_N 200'000
using namespace std;
typedef long long ll;

ll N, K;
ll A[MAX_N];

void solve() {
  vector<ll> neg;
  vector<ll> pos;
  int cnt_pos_10 = 0;
  int cnt_neg_10 = 0;
  for (int i = 0; i < N; ++i) {
    if (A[i] < 0) {
      neg.push_back(A[i]);
    } else if (A[i] > 0) {
      pos.push_back(A[i]);
    }
    if (A[i] == 1'000'000'000) {
      ++cnt_pos_10;
    }
    if (A[i] == -1'000'000'000) {
      ++cnt_neg_10;
    }
  }
  printf("N=%lld, K=%lld\n", N, K);
  printf("neg.size=%ld , pos.size=%ld\n", neg.size(), pos.size());
  printf("cnt_neg_10=%d, cnt_pos_10=%d\n", cnt_neg_10, cnt_pos_10);
  ll res = 1;
  for (int i = 0; i < K - 2; ++i) {
    res = res * 1'000'000'000 % MOD;
  }
  for (int i = 0; i < 2; ++i) {
    res = res * 999'999'998 % MOD;
  }
  printf("%lld\n", res);
}

int main() {
  ifstream ifs("hand_05.txt");
  ifs >> N >> K;
  for (int i = 0; i < N; ++i) {
    ifs >> A[i];
  }
  solve();
}
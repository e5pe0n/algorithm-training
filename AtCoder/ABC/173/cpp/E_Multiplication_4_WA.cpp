#include <bits/stdc++.h>
#define INF 2'000'000'000'000'000'000
#define MOD 1'000'000'007
#define MAX_N 200'000
using namespace std;
typedef long long ll;

ll N, K;
ll A[MAX_N];

void solve() {
  vector<ll> neg;
  vector<ll> pos;
  for (int i = 0; i < N; ++i) {
    if (A[i] > 0) {
      pos.push_back(A[i]);
    } else if (A[i] < 0) {
      neg.push_back(A[i]);
    }
  }
  if (pos.size() + neg.size() < K) {
    printf("0\n");
    return;
  }

  sort(neg.begin(), neg.end());
  sort(pos.begin(), pos.end());
  vector<ll> abs_neg{0};
  vector<ll> abs_pos{0};
  vector<ll> mul_neg{1};
  vector<ll> mul_pos{1};
  for (int i = 0; i < neg.size(); ++i) {
    abs_neg.push_back(abs_neg[abs_neg.size() - 1] + abs(neg[i]));
    mul_neg.push_back(mul_neg[mul_neg.size() - 1] * neg[i] % MOD);
  }
  for (int i = pos.size() - 1; i >= 0; --i) {
    abs_pos.push_back(abs_pos[abs_pos.size() - 1] + abs(pos[i]));
    mul_pos.push_back(mul_pos[mul_pos.size() - 1] * pos[i] % MOD);
  }
  ll res = 1;
  ll max_t = -INF;
  int n_neg = abs_neg.size();
  int n_pos = abs_pos.size();
  for (int i = 0; i < K / 2 + 1; ++i) {
    int i_pos = K - i * 2;
    int i_neg = i * 2;
    if (0 <= i_pos && i_pos < n_pos && 0 <= i_neg && i_neg < n_neg) {
      ll t = abs_pos[i_pos] + abs_neg[i_neg];
      if (t > max_t) {
        max_t = t;
        res = mul_pos[i_pos] * mul_neg[i_neg] % MOD;
        res = (res + MOD) % MOD;
      }
    }
  }
  if (max_t == -INF && neg.size() + pos.size() < N) {
    res = 0;
  } else {
    int k = 0;
    int i_neg = neg.size() - 1;
    int i_pos = 0;
    while (k < K && i_neg >= 0 && i_pos < pos.size()) {
      if (abs(neg[i_neg]) < abs(pos[i_pos])) {
        res = res * neg[i_neg--] % MOD;
        res = (res + MOD) % MOD;
      } else {
        res = res * pos[i_pos++] % MOD;
        res = (res + MOD) % MOD;
      }
      ++k;
    }
    while (i_neg < 0 && k < K) {
      res = res * pos[i_pos++] % MOD;
      res = (res + MOD) % MOD;
      ++k;
    }
    while (i_pos >= pos.size() && k < K) {
      res = res * neg[i_neg--] % MOD;
      res = (res + MOD) % MOD;
      ++k;
    }
  }
  printf("%lld\n", res);
}

int main() {
  // cin >> N >> K;
  // for (int i = 0; i < N; ++i) {
  //   cin >> A[i];
  // }
  ifstream ifs("hand_05.txt");
  ifs >> N >> K;
  for (int i = 0; i < N; ++i) {
    ifs >> A[i];
  }
  solve();
}
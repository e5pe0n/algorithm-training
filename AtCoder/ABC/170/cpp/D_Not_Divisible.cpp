#include <bits/stdc++.h>
#define MAX_N 200'000
#define MAX_A 1'000'000
using namespace std;

int N;
int A[MAX_N];
int cnt[MAX_A + 1];

vector<int> divisors(int n) {
  vector<int> res;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      res.push_back(i);
      if (n / i != i) {
        res.push_back(n / i);
      }
    }
  }
  return res;
}

void solve() {
  for (int i = 0; i < N; ++i) {
    ++cnt[A[i]];
  }
  int res = 0;
  for (int i = 0; i < N; ++i) {
    vector<int> v = divisors(A[i]);
    bool found = false;
    for (auto n : v) {
      if (n == A[i] && cnt[n] == 1) {
        continue;
      }
      if (cnt[n] > 0) {
        found = true;
        break;
      }
    }
    if (!found) {
      ++res;
    }
  }
  printf("%d\n", res);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}
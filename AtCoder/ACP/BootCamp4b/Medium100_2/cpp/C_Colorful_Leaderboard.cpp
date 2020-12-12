#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;

int N;
int A[MAX_N];
bool used[8];

void solve() {
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    if (A[i] >= 3200) {
      ++cnt;
    } else {
      used[A[i] / 400] = true;
    }
  }
  int min_res = 0;
  int max_res = 0;
  for (int i = 0; i < 8; ++i) {
    min_res += used[i];
  }
  max_res = min_res + cnt;
  min_res += min_res == 0 && cnt;
  printf("%d %d\n", min_res, max_res);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}
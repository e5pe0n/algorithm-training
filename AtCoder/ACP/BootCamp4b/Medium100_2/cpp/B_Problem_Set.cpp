#include <bits/stdc++.h>
#define MAX_N 200'000
#define MAX_M 200'000
using namespace std;

int N, M;
int D[MAX_N], T[MAX_M];

void solve() {
  map<int, int> cnt_D;
  for (int i = 0; i < N; ++i) {
    ++cnt_D[D[i]];
  }
  map<int, int> cnt_T;
  for (int i = 0; i < M; ++i) {
    ++cnt_T[T[i]];
  }
  for (auto p : cnt_T) {
    if (p.second > cnt_D[p.first]) {
      puts("NO");
      return;
    }
  }
  puts("YES");
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> D[i];
  }
  cin >> M;
  for (int i = 0; i < M; ++i) {
    cin >> T[i];
  }
  solve();
}
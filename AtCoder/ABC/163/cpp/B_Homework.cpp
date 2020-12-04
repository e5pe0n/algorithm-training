#include <bits/stdc++.h>
using namespace std;

int N, M, A;

int main() {
  cin >> N >> M;
  int cnt = 0;
  for (int i = 0; i < M; ++i) {
    cin >> A;
    cnt += A;
  }
  int res = max(-1, N - cnt);
  printf("%d\n", res);
}
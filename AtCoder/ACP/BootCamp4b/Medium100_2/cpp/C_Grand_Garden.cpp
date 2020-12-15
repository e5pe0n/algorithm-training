#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;

int N;
int H[MAX_N];

void solve() {
  int res = 0;
  int h = *max_element(H, H + N);
  if (h == 0) {
    puts("0");
    return;
  }
  while (true) {
    int i = 0;
    bool f = false;
    while (i < N) {
      while (i < N && H[i] == h) {
        --H[i++];
        f = true;
      }
      res += f;
      f = false;
      ++i;
    }
    --h;
    if (h == 0) {
      printf("%d\n", res);
      return;
    }
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> H[i];
  }
  solve();
}
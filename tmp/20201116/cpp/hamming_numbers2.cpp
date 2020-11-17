#include <chrono>
#include <iostream>
#include <stdio.h>

#define MAX_H 10'000

using namespace std;
typedef long long ll;

int N[] = {50, 1000, 10000, 1000000, 1000000000};
int H[MAX_H];
int F[] = {2, 3, 5};

void solve(int n) {
  auto start = chrono::high_resolution_clock::now();
  fill(H, H + MAX_H, 0);
  H[0] = 1;
  int cnt = 1;
  int right = cnt;
  for (int j = 0; j < 3; ++j) {
    for (int left = 0; left < right; ++left) {
      ll x = F[j];
      while (H[left] * x <= n) {
        H[cnt++] = H[left] * x;
        x *= F[j];
      }
    }
    right = cnt;
  }
  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
  printf("%d:%d (%ld[ms])\n", n, cnt, duration);
}

int main() {
  for (int i = 0; i < 5; ++i) {
    solve(N[i]);
  }
}

// 50:24 (18[ms])
// 1000:86 (10[ms])
// 10000:175 (11[ms])
// 1000000:507 (12[ms])
// 1000000000:1530 (16[ms])
#include <chrono>
#include <iostream>
#include <stdio.h>

#define MAX_n 1'000'000'000

using namespace std;

int n = 50;
int F[] = {2, 3, 5};

int main() {
  auto start = chrono::high_resolution_clock::now();
  int res = 1;
  for (int i = 2; i <= n; ++i) {
    int t = i;
    for (int j = 0; j < 3; ++j) {
      while (t % F[j] == 0) {
        t /= F[j];
      }
    }
    if (t == 1) {
      printf("%d\n", i);
      ++res;
    }
  }
  printf("%d\n", res);
  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
  printf("duration[ms]=%ld\n", duration);
}
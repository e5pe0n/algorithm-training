#include <chrono>
#include <iostream>
#include <stdio.h>

#define MAX_n 1'000'000'000

using namespace std;

int n;
int fct[] = {2, 3, 5};

int main() {
  cin >> n;
  auto start = chrono::high_resolution_clock::now();
  int res = 1;
  for (int i = 2; i <= n; ++i) {
    int t = i;
    for (int j = 0; j < 3; ++j) {
      while (t % fct[j] == 0) {
        t /= fct[j];
      }
    }
    if (t == 1) {
      ++res;
    }
  }
  printf("%d\n", res);
  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
  printf("duration[ms]=%ld\n", duration);
}
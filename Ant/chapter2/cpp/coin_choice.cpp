#include <algorithm>
#include <fstream>
#include <stdio.h>

using namespace std;

int C[6]{};
int V[] = {1, 5, 10, 50, 100, 500};
int A;

int main() {
  ifstream ifs("../testset/coin_choice/test1.txt");
  for (int i = 0; i < 6; ++i) {
    ifs >> C[i];
  }
  ifs >> A;
  int ans = 0;
  for (int i = 5; i >= 0; --i) {
    int t = min(A / V[i], C[i]);
    A -= V[i] * t;
    ans += t;
  }
  printf("%d\n", ans);
}
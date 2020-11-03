#include <fstream>
#include <math.h>
#include <stdio.h>

#define MAX_N 100'000
#define INF 1'000'000'000

using namespace std;

int N, K;
double L[MAX_N];

bool C(float x) {
  int n = 0;
  for (int i = 0; i < N; ++i) {
    n += (int)(L[i] / x);
  }
  return n >= K;
}

int main() {
  ifstream ifs("../testset/cable_master/test1.txt");
  ifs >> N >> K;
  for (int i = 0; i < N; ++i) {
    ifs >> L[i];
  }
  double lb = 0;
  double ub = INF;
  for (int i = 0; i < 100; ++i) { // n = 100 -> presition is 10^(-30)
    double mid = (lb + ub) / 2;
    if (C(mid)) {
      lb = mid;
    } else {
      ub = mid;
    }
  }
  printf("%.2f\n", floor(ub * 100) / 100);
}
#include <algorithm>
#include <fstream>
#include <math.h>
#include <stdio.h>

#define g 10.0
#define MAX_N 100

using namespace std;

int N, H, R, T;
double y[MAX_N];

double calc(int t) {
  if (t <= 0) {
    return H;
  }
  double _t = sqrt(2 * H / g);
  int k = (int)(t / _t);
  if (k % 2 == 0) {
    double dt = t - k * _t;
    return H - g * dt * dt / 2;
  } else {
    double dt = (k + 1) * _t - t;
    return H - g * dt * dt / 2;
  }
}

int main() {
  ifstream ifs("../testset/elastic_collision/test2.txt");
  ifs >> N >> H >> R >> T;
  for (int i = 0; i < N; ++i) {
    y[i] = calc(T - i);
  }
  sort(y, y + N);
  for (int i = 0; i < N; ++i) {
    double res = y[i] + 2 * R * i / 100.0;
    printf("%.2f%c", res, i == N - 1 ? '\n' : ' ');
  }
}
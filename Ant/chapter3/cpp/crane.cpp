#include <fstream>
#include <math.h>
#include <stdio.h>

#define MAX_N 10000
#define MAX_C 10000

using namespace std;

const int ST_SIZE = (1 << 15) - 1;

int N, C;
int L[MAX_N];
int S[MAX_C], A[MAX_C];

double vx[ST_SIZE], vy[ST_SIZE], ang[ST_SIZE];
double prv[MAX_N];

void init(int k, int left, int right) {
  ang[k] = vx[k] = 0.0;
  if (right - left == 1) {
    vy[k] = L[left];
  } else {
    int chl = k * 2 + 1;
    int chr = k * 2 + 2;
    init(chl, left, (left + right) / 2);
    init(chr, (left + right) / 2, right);
    vy[k] = vy[chl] + vy[chr];
  }
}

void change(int k, double a, int v, int left, int right) {
  if (left <= k && k + 1 < right) { // move k + 1 th crane if k is passed
    int chl = v * 2 + 1;
    int chr = v * 2 + 2;
    int m = (left + right) / 2;
    change(k, a, chl, left, m);
    change(k, a, chr, m, right);
    if (k < m) {
      ang[v] += a;
    }
    double s = sin(ang[v]);
    double c = cos(ang[v]);
    vx[v] = vx[chl] + (c * vx[chr] - s * vy[chr]);
    vy[v] = vy[chl] + (s * vx[chr] + c * vy[chr]);
  }
}

int main() {
  ifstream ifs("../testset/crane/test2.txt");
  ifs >> N >> C;
  for (int i = 0; i < N; ++i) {
    ifs >> L[i];
  }
  for (int i = 0; i < C; ++i) {
    int s;
    ifs >> s;
    S[i] = s - 1;
  }
  for (int i = 0; i < C; ++i) {
    ifs >> A[i];
  }
  init(0, 0, N);
  for (int i = 0; i < N; ++i) {
    prv[i] = M_PI;
  }
  for (int i = 0; i < C; ++i) {
    int s = S[i];
    double a = A[i] / 360.0 * 2 * M_PI;
    change(s, a - prv[s], 0, 0, N);
    prv[s] = a;
    printf("%.2f %.2f\n", vx[0], vy[0]);
  }
}
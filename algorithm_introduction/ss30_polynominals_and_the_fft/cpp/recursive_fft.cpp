#include <cmath>
#include <complex>
#include <stdio.h>
#include <vector>

using namespace std;

vector<complex<double>> recursive_fft(vector<complex<double>> a) {
  int n = a.size();
  if (n == 1) {
    return a;
  }
  double PI = acos(-1);
  complex<double> wn = polar(1.0, 2 * PI);
  complex<double> w = 1.0;
  vector<complex<double>> A0;
  vector<complex<double>> A1;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      A0.push_back(a[i]);
    } else {
      A1.push_back(a[i]);
    }
  }
  vector<complex<double>> Y0 = recursive_fft(A0);
  vector<complex<double>> Y1 = recursive_fft(A1);
  vector<complex<double>> Y(n);
  for (int i = 0; i < n / 2; ++i) {
    Y[i] = Y0[i] + w * Y1[i];
    Y[i + n / 2] = Y0[i] - w * Y1[i];
    w *= wn;
  }
  return Y;
}

int main() {}
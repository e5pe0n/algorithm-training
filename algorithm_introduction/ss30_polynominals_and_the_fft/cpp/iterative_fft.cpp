#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <math.h>
#include <stdio.h>
#include <string>
#include <vector>

#define N 100'000

using namespace std;

int rev(int k, int n) {
  bitset<N> B(k);
  string s = B.to_string().substr(N - n, n);
  reverse(s.begin(), s.end());
  return stoi(s, nullptr, 2);
}

vector<complex<double>> bit_reverse_copy(vector<complex<double>> a) {
  int n = a.size();
  vector<complex<double>> A(n);
  for (int k = 0; k < n; ++k) {
    A[rev(k, n)] = a[k];
  }
  return A;
}

vector<complex<double>> iterative_fft(vector<complex<double>> a) {
  int n = a.size();
  vector<complex<double>> A = bit_reverse_copy(a);
  double PI = acos(-1);
  for (int s = 0; s < (int)log2((double)n)) {
    int m = (int)pow(2, s);
    complex<double> wm = polar(1.0, 2 * PI / m);
    for (int k = 0; k < n; k += m) {
      complex<double> w = 1;
      for (int j = 0; j < m / 2; ++j) {
        complex<double> t = w * A[k + j];
        complex<double> u = A[k + j];
        A[k + j] = u + t;
        A[k + j + m / 2] = u - t;
        w *= wm;
      }
    }
  }
  return A;
}

int main() {}
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>

#define MAX_N 100'000

typedef long long ll;

using namespace std;

int A[MAX_N];
int B[MAX_N];

int main() {
  int N;
  cin >> N;
  ll a = 0;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    a += (ll)A[i];
  }
  ll b = 0;
  for (int i = 0; i < N; ++i) {
    cin >> B[i];
    b += (ll)B[i];
  }
  if (a < b) {
    printf("-1\n");
    return 0;
  }
  vector<int> V;
  vector<int> _V;
  for (int i = 0; i < N; ++i) {
    ll d = A[i] - B[i];
    if (d > 0) {
      V.push_back(d);
    } else if (d < 0) {
      _V.push_back(-d);
    }
  }
  int M = V.size();
  int _M = _V.size();
  if (_M == 0) {
    printf("0\n");
    return 0;
  }
  sort(V.begin(), V.end());
  sort(_V.begin(), _V.end());
  int i = M - 1;
  int _i = _M - 1;
  ll t = 0;
  int res = 0;
  while (_i >= 0) {
    if (t >= 0) {
      t -= _V[_i--];
      ++res;
    } else {
      t += V[i--];
      ++res;
    }
  }
  printf("%d\n", res + (t < 0));
}
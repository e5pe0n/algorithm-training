#include <iostream>
#include <stdio.h>

#define MAX_N 100'001

typedef long long ll;

using namespace std;

int A[MAX_N]{};

int main() {
  ll N, K;
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  ll cnt = 0;
  ll left = 0;
  ll right = 0;
  ll t = A[right];
  while (right < N) {
    if (t >= K) {
      cnt += N - right;
    }
    if (t >= K && left < right) {
      t -= A[left++];
    } else if (t >= K && left == right) {
      ++left;
      t = A[++right];
    } else {
      t += A[++right];
    }
  }
  printf("%lld\n", cnt);
}
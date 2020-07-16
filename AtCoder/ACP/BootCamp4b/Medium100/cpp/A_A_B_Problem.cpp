#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>

typedef long long ll;

using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  if (A > B) {
    printf("0\n");
    return 0;
  }
  if (N == 1) {
    printf("%d\n", A == B);
  } else if (N == 2) {
    printf("1\n");
  } else {
    printf("%lld\n", (ll)(B - A) * (N - 2) + 1);
  }
}
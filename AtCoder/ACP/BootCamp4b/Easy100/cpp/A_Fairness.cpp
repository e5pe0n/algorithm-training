#include <iostream>
#include <math.h>
#include <stdio.h>

#define MAX_N 1'000'000'000'000'000'000

typedef long long ll;

using namespace std;

int main() {
  ll A, B, C, K;
  cin >> A >> B >> C >> K;
  ll res = K % 2 == 0 ? A - B : B - A;
  if (abs(res) >= MAX_N) {
    printf("Unfair\n");
  } else {
    printf("%lld\n", res);
  }
}
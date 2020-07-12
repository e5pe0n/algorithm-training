#include <iostream>
#include <math.h>
#include <stdio.h>

typedef long long ll;

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  printf("%lld\n", K * (ll)pow(K - 1, N - 1));
}
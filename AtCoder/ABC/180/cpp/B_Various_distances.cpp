#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>

#define MAX_N 100'000

using namespace std;

typedef long long ll;

int N;

int main() {
  cin >> N;
  ll md = 0;
  ll ed = 0;
  ll cd = 0;
  for (int i = 0; i < N; ++i) {
    ll x;
    cin >> x;
    md += abs(x);
    ed += x * x;
    cd = max(cd, abs(x));
  }
  printf("%lld\n", md);
  printf("%.10f\n", sqrt(ed));
  printf("%lld\n", cd);
}
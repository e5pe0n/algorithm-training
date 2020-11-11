#include <algorithm>
#include <stdio.h>

#define M 10000

using namespace std;

typedef long long ll;

ll d[30];

ll f(ll i) {
  if (i == 0) {
    return 0;
  }
  if (i == 1) {
    return 1;
  }
  if (d[i] > 0) {
    return d[i];
  }
  return d[i] = f(i - 2) + f(i - 1);
}

int main() { printf("%lld\n", f(50) % M); }
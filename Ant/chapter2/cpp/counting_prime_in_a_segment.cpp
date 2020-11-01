#include <fstream>
#include <stdio.h>

#define MAX_L 1'000'000
#define MAX_SQRT_B 1'000'000

using namespace std;

typedef long long ll;

ll a, b;
bool is_prime_small[MAX_SQRT_B];
bool is_prime[MAX_L];

void segment_sieve(ll a, ll b) {
  for (ll i = 0; i * i < b; ++i) {
    is_prime_small[i] = true;
  }
  for (ll i = 0; i < b - a; ++i) {
    is_prime[i] = true;
  }
  for (ll i = 2; i * i < b; ++i) {
    if (is_prime_small[i]) {
      for (ll j = i * 2; j * j < b; j += i) {
        is_prime_small[j] = false;
      }
      // ((a + i - 1) / i) * i = the smallest multiple of i which is more than or equal to a
      for (ll j = max(2LL, (a + i - 1) / i) * i; j < b; j += i) {
        is_prime[j - a] = false;
      }
    }
  }
}

int main() {
  ifstream ifs("../testset/counting_prime_in_a_segment/test2.txt");
  ifs >> a >> b;
  segment_sieve(a, b);
  int res = 0;
  for (ll i = 0; i < b - a; ++i) {
    res += is_prime[i];
  }
  printf("%d\n", res);
}
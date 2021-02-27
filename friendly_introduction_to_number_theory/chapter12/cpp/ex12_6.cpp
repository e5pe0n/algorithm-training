#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  printf("gcd(1338, 1115)=%lld\n",
         __gcd(1338LL, 1115LL)); // 223 so the prime is only 223
  printf("gcd(1438, 1115)=%lld\n",
         __gcd(1438LL, 1115LL)); // 1 so there are infinitely many such primes
}
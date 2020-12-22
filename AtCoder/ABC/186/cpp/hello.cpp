#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> divisors(ll n) {
  vector<ll> res;
  for (ll i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      res.push_back(i);
      if (n / i != i) {
        res.push_back(n / i);
      }
    }
  }
  sort(res.begin(), res.end()); // optional
  return res;
}

int main() {
  ll N = 12;
  vector<ll> res = divisors(N);
  for (int i = 0; i < res.size(); ++i) {
    printf("%lld%c", res[i], i == res.size() - 1 ? '\n' : ' '); // 1 2 3 4 6 12
  }
}

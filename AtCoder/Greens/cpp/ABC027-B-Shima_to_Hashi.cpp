#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];
ll used[MAX_N];

int main() {
  cin >> N;
  ll sum = 0;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
    sum += A[i];
  }
  if (sum % N != 0) {
    puts("-1");
    return 0;
  }
  ll a = sum / N;
  ll t = 0;
  ll res = 0;
  for (ll i = 0; i < N; ++i) {
    t += A[i] - a;
    if (t != 0) ++res;
  }
  printf("%lld\n", res);
}
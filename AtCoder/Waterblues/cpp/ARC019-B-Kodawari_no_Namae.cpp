#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string A;

int main() {
  cin >> A;
  ll N = A.size();
  ll left = 0, right = N - 1;
  ll diff = 0;
  ll res = 0;
  while (left <= right) {
    if (left == right)
      res += 25 * (diff > 0);
    else if (A[left] != A[right]) {
      ++diff;
      res += 24 * 2;
    } else
      res += 25 * 2;
    ++left;
    --right;
  }
  if (diff > 1) res += diff * 2;
  printf("%lld\n", res);
}
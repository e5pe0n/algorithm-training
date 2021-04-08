#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  vector<ll> V{1, 5, 3};
  sort(V.begin(), V.end(), less<ll>());
  for (auto v : V)
    printf("%lld\n", v); // 1 3 5
}
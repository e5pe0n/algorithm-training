#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string A, B;

void solve() {
  ll sum_A = 0;
  for (auto a : A) {
    sum_A += a - '0';
  }
  ll sum_B = 0;
  for (auto b : B) {
    sum_B += b - '0';
  }
  printf("%lld\n", max(sum_A, sum_B));
}

int main() {
  cin >> A >> B;
  solve();
}
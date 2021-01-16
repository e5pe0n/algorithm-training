#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
string sv = "Vacant";
string sm = "Male";
string sf = "Female";

void solve() {
  ll left = 0;
  ll right = N - 1;
  string left_s;
  string mid_s;
  string right_s;
  printf("%lld\n", left);
  cin >> left_s;
  printf("%lld\n", right);
  cin >> right_s;
  if (left_s == sv || right_s == sv) return;
  while (true) {
    ll mid = (left + right) / 2;
    printf("%lld\n", mid);
    cin >> mid_s;
    if (mid_s == sv) return;
    if (((mid - left) % 2 == 0 && mid_s == left_s)
        || ((mid - left) % 2 != 0 && mid_s != left_s)) {
      left = mid;
      left_s = mid_s;
    } else
      right = mid;
    right_s = mid_s;
  }
}

int main() {
  setbuf(stdout, NULL);
  cin >> N;
  solve();
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;

void solve() {
  int left = 0;
  int right = S.size() - 1;
  ll res = 0;
  while (left < right) {
    if (S[left] == S[right]) {
      ++left;
      --right;
    } else {
      if (S[left] == 'x') {
        ++res;
        ++left;
      } else if (S[right] == 'x') {
        ++res;
        --right;
      } else {
        res = -1;
        break;
      }
    }
  }
  printf("%lld\n", res);
}

int main() {
  cin >> S;
  solve();
}
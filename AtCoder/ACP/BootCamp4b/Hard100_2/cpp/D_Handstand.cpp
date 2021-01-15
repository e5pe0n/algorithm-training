#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, K;
string S;

void solve() {
  ll left = 0;
  ll right = 0;
  ll cnt = 0;
  while (right < N) {
    bool f = false;
    while (S[right] == '0') {
      right++;
      f = true;
    }
    while (S[right] == '1') {
      ++right;
    }
    cnt += f;
    if (cnt >= K) break;
  }
  ll res = right - left;
  while (right < N) {
    while (right < N && S[right] == '0') {
      ++right;
    }
    while (right < N && S[right] == '1') {
      ++right;
    }
    while (left < N && S[left] == '1') {
      ++left;
    }
    while (left < N && S[left] == '0') {
      ++left;
    }
    res = max(res, right - left);
  }
  printf("%lld\n", res);
}

int main() {
  cin >> N >> K >> S;
  solve();
}
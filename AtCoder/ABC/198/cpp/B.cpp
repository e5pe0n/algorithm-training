#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;

int main() {
  cin >> S;
  ll front = 0, back = 0;
  for (ll i = 0; i < S.size(); ++i) {
    if (S[i] != '0') break;
    ++front;
  }
  for (ll i = S.size() - 1; i >= 0; --i) {
    if (S[i] != '0') break;
    ++back;
  }
  if (front > back) {
    puts("No");
    return 0;
  }
  S = S.substr(front, S.size() - back - front);
  ll left = 0, right = S.size() - 1;
  while (left < right) {
    if (S[left] != S[right]) {
      puts("No");
      return 0;
    }
    ++left, --right;
  }
  puts("Yes");
}
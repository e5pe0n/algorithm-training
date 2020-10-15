#include <iostream>
#include <stdio.h>
#include <string>

typedef long long ll;

using namespace std;

int main() {
  string s;
  cin >> s;
  int N = s.size();
  int i = 0;
  ll ans = 0;
  while (i < N) {
    while (i < N && s[i] != 'A') {
      ++i;
    }
    int cnt_A = 0;
    while (i < N && s[i] == 'A') {
      while (i < N && s[i] == 'A') {
        ++i;
        ++cnt_A;
      }
      while (i + 1 < N && s[i] == 'B' && s[i + 1] == 'C') {
        i += 2;
        ans += cnt_A;
      }
    }
  }
  printf("%lld\n", ans);
}
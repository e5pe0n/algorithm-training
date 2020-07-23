#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
#include <unordered_map>

typedef long long ll;

using namespace std;

int main() {
  int N;
  cin >> N;
  unordered_map<string, int> S;
  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    ++S[s];
  }
  ll res = 0;
  for (auto &s : S) {
    res += (ll)s.second * (s.second - 1) / 2;
  }
  printf("%lld\n", res);
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const string W[] = {"H", "2B", "3B", "HR"};
set<string> T;

int main() {
  for (ll i = 0; i < 4; ++i) {
    string s;
    cin >> s;
    T.insert(s);
  }
  for (ll i = 0; i < 4; ++i) {
    if (T.find(W[i]) == T.end()) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
}
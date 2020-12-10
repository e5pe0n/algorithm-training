#include <bits/stdc++.h>
using namespace std;

string S;

int main() {
  cin >> S;
  string res;
  for (auto s : S) {
    res += "x";
  }
  puts(res.c_str());
}
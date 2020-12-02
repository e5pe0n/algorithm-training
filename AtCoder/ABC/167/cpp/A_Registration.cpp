#include <bits/stdc++.h>
using namespace std;

string S, T;

int main() {
  cin >> S >> T;
  if (S == T.substr(0, T.size() - 1)) {
    puts("Yes");
  } else {
    puts("No");
  }
}
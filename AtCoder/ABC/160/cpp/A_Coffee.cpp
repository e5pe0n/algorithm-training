#include <bits/stdc++.h>
using namespace std;

string S;

int main() {
  cin >> S;
  if (S[2] == S[3] && S[4] == S[5]) {
    puts("Yes");
  } else {
    puts("No");
  }
}
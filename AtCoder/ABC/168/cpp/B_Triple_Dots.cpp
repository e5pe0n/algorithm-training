#include <bits/stdc++.h>
using namespace std;

int K;
string S;

int main() {
  cin >> K >> S;
  if (S.size() <= K) {
    puts(S.c_str());
  } else {
    puts((S.substr(0, K) + "...").c_str());
  }
}
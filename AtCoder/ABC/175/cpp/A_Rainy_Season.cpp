#include <bits/stdc++.h>
using namespace std;

string S;

int main() {
  cin >> S;
  int res = 0;
  if (S == "RRR") {
    res = 3;
  } else if ((S[0] == 'R' && S[1] == 'R') || (S[1] == 'R' && S[2] == 'R')) {
    res = 2;
  } else if (S[0] == 'R' || S[1] == 'R' || S[2] == 'R') {
    res = 1;
  }
  printf("%d\n", res);
}
#include <bits/stdc++.h>
using namespace std;

int A, B, C, D;

int main() {
  cin >> A >> B >> C >> D;
  while (A > 0 || C > 0) {
    C -= B;
    if (C <= 0) {
      break;
    }
    A -= D;
  }
  if (A > 0) {
    puts("Yes");
  } else {
    puts("No");
  }
}
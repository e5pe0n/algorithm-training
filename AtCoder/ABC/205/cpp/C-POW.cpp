#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll A, B, C;

int main() {
  cin >> A >> B >> C;
  if (A >= 0 && B >= 0) {
    if (A > B)
      puts(">");
    else if (A < B)
      puts("<");
    else
      puts("=");
  } else if (A < 0 && B < 0) {
    if (C % 2 == 0) {
      if (abs(A) > abs(B))
        puts(">");
      else if (abs(A) < abs(B))
        puts("<");
      else
        puts("=");
    } else {
      if (abs(A) < abs(B))
        puts(">");
      else if (abs(A) > abs(B))
        puts("<");
      else
        puts("=");
    }
  } else {
    if (C % 2 == 0) {
      if (abs(A) > abs(B))
        puts(">");
      else if (abs(A) < abs(B))
        puts("<");
      else
        puts("=");
    } else {
      if (A > B)
        puts(">");
      else if (A < B)
        puts("<");
      else
        puts("=");
    }
  }
}
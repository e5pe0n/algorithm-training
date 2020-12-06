#include <bits/stdc++.h>
using namespace std;

int X;

int main() {
  cin >> X;
  int res = (X / 500) * 1000 + (X - X / 500 * 500) / 5 * 5;
  printf("%d\n", res);
}
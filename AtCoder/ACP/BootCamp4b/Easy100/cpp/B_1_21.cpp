#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  string s = to_string(a) + to_string(b);
  int n = stoi(s);
  int _n = (int)sqrt(n);
  if (_n * _n == n) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}
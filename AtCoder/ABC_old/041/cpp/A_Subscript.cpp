#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string s;
  int i;
  cin >> s >> i;
  printf("%c\n", s[i - 1]);
}
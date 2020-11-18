#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string S;

int main() {
  cin >> S;
  if (S[S.size() - 1] == 's') {
    S += "es";
  } else {
    S += "s";
  }
  printf("%s\n", S.c_str());
}
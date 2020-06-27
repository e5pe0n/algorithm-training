#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string A, B;
  cin >> A >> B;
  if (A.size() < B.size()) {
    printf("%s\n", B.c_str());
  } else {
    printf("%s\n", A.c_str());
  }
}
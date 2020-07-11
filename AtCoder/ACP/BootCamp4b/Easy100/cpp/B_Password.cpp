#include <iostream>
#include <stdio.h>
#include <string>

#define MAX_N 50

using namespace std;

int main() {
  string O, E;
  cin >> O >> E;
  if (O.size() == E.size()) {
    for (int i = 0; i < O.size(); ++i) {
      printf("%c", O[i]);
      printf("%c", E[i]);
    }
    printf("\n");
  } else {
    printf("%c", O[0]);
    for (int i = 0; i < E.size(); ++i) {
      printf("%c", E[i]);
      printf("%c", O[i + 1]);
    }
    printf("\n");
  }
}
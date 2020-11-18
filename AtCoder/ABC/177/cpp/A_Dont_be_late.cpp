#include <iostream>
#include <stdio.h>

using namespace std;

double D, T, S;

int main() {
  cin >> D >> T >> S;
  if (D / S <= T) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}
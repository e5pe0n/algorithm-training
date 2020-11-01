#include <iostream>
#include <stdio.h>

using namespace std;

int N;

int main() {
  cin >> N;
  if (N % 2 == 0) {
    printf("White\n");
  } else {
    printf("Black\n");
  }
}
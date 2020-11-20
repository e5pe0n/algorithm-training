#include <iostream>
#include <map>
#include <stdio.h>

#define N_MAX 100

using namespace std;

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    char s;
    cin >> s;
    if (s == 'Y') {
      printf("Four\n");
      return 0;
    }
  }
  printf("Three\n");
}
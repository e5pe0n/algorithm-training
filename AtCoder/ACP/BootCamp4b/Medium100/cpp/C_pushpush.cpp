#include <iostream>
#include <stdio.h>

#define MAX_N 200'000

using namespace std;

int B[MAX_N];

int main() {
  int n;
  cin >> n;
  int j = n / 2;
  int k = 1;
  if (n % 2 == 0) {
    k = -1;
  }
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    B[j] = a;
    j += k * i;
    k = -k;
  }
  for (int i = 0; i < n; ++i) {
    printf("%d ", B[i]);
  }
  printf("\n");
}
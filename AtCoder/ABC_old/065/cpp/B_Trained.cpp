#include <iostream>
#include <stdio.h>

#define MAX_N 100'000

using namespace std;

int A[MAX_N]{};
bool selected[MAX_N]{};

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  int a = 1;
  int cnt = 0;
  while (a != 2 && !selected[a - 1]) {
    selected[a - 1] = true;
    a = A[a - 1];
    ++cnt;
  }
  if (a == 2) {
    printf("%d\n", cnt);
  } else {
    printf("-1\n");
  }
}
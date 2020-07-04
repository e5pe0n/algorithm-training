#include <iostream>
#include <stdio.h>
#include <unordered_set>

#define MAX_N 100

using namespace std;

int main() {
  int N;
  cin >> N;
  unordered_set<int> S;
  for (int i = 0; i < N; ++i) {
    int d;
    cin >> d;
    S.insert(d);
  }
  printf("%d\n", (int)S.size());
}
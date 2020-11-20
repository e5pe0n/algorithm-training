#include <iostream>
#include <stdio.h>
#include <unordered_set>

using namespace std;

int main() {
  int N;
  cin >> N;
  unordered_set<int> D;
  for (int i = 0; i < N; ++i) {
    int d;
    cin >> d;
    D.insert(d);
  }
  printf("%d\n", (int)D.size());
}
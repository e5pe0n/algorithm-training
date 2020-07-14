#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <unordered_set>

using namespace std;

int main() {
  int N;
  cin >> N;
  unordered_set<int> S;
  int _S = 0;
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    if (a <= 399) {
      S.insert(0);
    } else if (400 <= a && a <= 799) {
      S.insert(1);
    } else if (800 <= a && a <= 1199) {
      S.insert(2);
    } else if (1200 <= a && a <= 1599) {
      S.insert(3);
    } else if (1600 <= a && a <= 1999) {
      S.insert(4);
    } else if (2000 <= a && a <= 2399) {
      S.insert(5);
    } else if (2400 <= a && a <= 2799) {
      S.insert(6);
    } else if (2800 <= a && a <= 3199) {
      S.insert(7);
    } else {
      ++_S;
    }
  }
  printf("%d %d\n", max(1, (int)S.size()), (int)S.size() + _S);
}
#include <bits/stdc++.h>
using namespace std;

int N, K;

int main() {
  cin >> N >> K;
  int res = 0;
  while (N > 0) {
    N /= K;
    ++res;
  }
  printf("%d\n", res);
}
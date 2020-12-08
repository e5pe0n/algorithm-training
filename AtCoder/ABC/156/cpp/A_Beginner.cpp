#include <bits/stdc++.h>
using namespace std;

int N, R;

int main() {
  cin >> N >> R;
  int res = R;
  if (N < 10) {
    res += 100 * (10 - N);
  }
  printf("%d\n", res);
}
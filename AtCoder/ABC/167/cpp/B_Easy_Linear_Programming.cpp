#include <bits/stdc++.h>
using namespace std;

int A, B, C, K;

int main() {
  cin >> A >> B >> C >> K;
  int res = min(A, K) - min(C, max(K - A - B, 0));
  printf("%d\n", res);
}
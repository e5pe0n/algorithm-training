#include <bits/stdc++.h>
using namespace std;

int N, M;

int main() {
  cin >> N >> M;
  printf("%d\n", N * (N - 1) / 2 + M * (M - 1) / 2);
}
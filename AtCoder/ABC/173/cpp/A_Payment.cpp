#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
  cin >> N;
  printf("%d\n", (int)ceil(N / 1000.0) * 1000 - N);
}
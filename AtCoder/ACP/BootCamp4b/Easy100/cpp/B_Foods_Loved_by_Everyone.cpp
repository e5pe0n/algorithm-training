#include <bitset>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  bitset<30> B;
  B.set();
  for (int i = 0; i < N; ++i) {
    int K;
    cin >> K;
    bitset<30> _B;
    for (int j = 0; j < K; ++j) {
      int a;
      cin >> a;
      _B.set(a - 1, true);
    }
    B &= _B;
  }
  int cnt = 0;
  for (int i = 0; i < M; ++i) {
    if (B.test(i)) {
      ++cnt;
    }
  }
  printf("%d\n", cnt);
}
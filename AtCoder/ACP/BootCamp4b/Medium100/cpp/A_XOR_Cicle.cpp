#include <bitset>
#include <iostream>
#include <stdio.h>
#include <unordered_map>

#define MAX_N 100'000

using namespace std;

int main() {
  int N;
  cin >> N;
  unordered_map<int, int> M;
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    ++M[a];
  }
  if (M.size() == 1 && M[0] == N) {
    printf("Yes\n");
  } else if (M.size() == 2 && N % 3 == 0 && M[0] == N / 3 && N - M[0] == 2 * (N / 3)) {
    printf("Yes\n");
  } else if (M.size() == 3 && N % 3 == 0) {
    bitset<MAX_N> B(0);
    for (auto &m : M) {
      if (m.second != N / 3) {
        printf("No\n");
        return 0;
      }
      bitset<MAX_N> _B(m.first);
      B ^= _B;
    }
    if (B.none()) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  } else {
    printf("No\n");
  }
}
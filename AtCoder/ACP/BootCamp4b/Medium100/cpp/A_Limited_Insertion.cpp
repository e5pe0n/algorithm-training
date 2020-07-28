#include <iostream>
#include <stdio.h>
#include <vector>

#define MAX_N 100

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> B;
  for (int i = 0; i < N; ++i) {
    int b;
    cin >> b;
    B.push_back(b - 1);
  }
  vector<int> res;
  for (int i = 0; i < N; ++i) {
    for (int j = B.size() - 1; j >= 0; --j) {
      if (B[j] == j) {
        res.push_back(j);
        B.erase(B.begin() + j);
        break;
      }
    }
  }
  if (B.size() == 0) {
    for (int i = res.size() - 1; i >= 0; --i) {
      printf("%d\n", res[i] + 1);
    }
  } else {
    printf("-1\n");
  }
}
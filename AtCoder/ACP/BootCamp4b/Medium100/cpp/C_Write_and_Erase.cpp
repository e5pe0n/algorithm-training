#include <iostream>
#include <stdio.h>
#include <unordered_map>

using namespace std;

int main() {
  int N;
  cin >> N;
  unordered_map<int, int> S;
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    ++S[a];
  }
  int cnt = 0;
  for (auto s : S) {
    if (s.second % 2 == 1) {
      ++cnt;
    }
  }
  printf("%d\n", cnt);
}
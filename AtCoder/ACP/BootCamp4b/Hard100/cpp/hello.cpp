#include <deque>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<vector<int>> V{{1, 2, 3}, {4, 5, 6}};
  deque<vector<int>> q(V.begin(), V.end());
  for (auto _q : q) {
    for (auto v : _q) {
      printf("%d ", v);
    }
    printf("\n");
  }
}
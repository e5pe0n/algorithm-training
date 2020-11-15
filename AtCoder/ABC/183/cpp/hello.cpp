#include <algorithm>
#include <functional>
#include <queue>
#include <stdio.h>

using namespace std;

int N = 5;
int X[] = {3, 4, 5, 2, 8};

int main() {
  auto comp = [](const int &left, const int &right) { return left < right; };
  priority_queue<int, vector<int>, decltype(comp)> q(comp);
  for (int i = 0; i < N; ++i) {
    q.push(X[i]);
  }
  while (!q.empty()) {
    printf("%d ", q.top());
    q.pop();
  }
  printf("\n");
  sort(X, X + N, comp);
  for (int i = 0; i < N; ++i) {
    printf("%d%c", X[i], i == N - 1 ? '\n' : ' ');
  }
  // priority_queue : [8 5 4 3 2]
  // sort           : [2 3 4 5 8]
}
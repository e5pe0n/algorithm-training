#include <fstream>
#include <queue>
#include <stdio.h>

#define MAX_N 1000

using namespace std;

int N, L, P;
int A[MAX_N + 1], B[MAX_N + 1];

int main() {
  ifstream ifs("../testset/expedition/test1.txt");
  ifs >> N >> L >> P;
  for (int i = 0; i < N; ++i) {
    ifs >> A[i];
  }
  for (int i = 0; i < N; ++i) {
    ifs >> B[i];
  }
  A[N] = L;
  B[N] = 0;
  ++N;
  priority_queue<int> q;
  int ans = 0, pos = 0, tank = P;
  for (int i = 0; i < N; ++i) {
    int d = A[i] - pos;
    while (tank - d < 0) {
      if (q.empty()) {
        printf("-1\n");
        return 0;
      }
      tank += q.top();
      q.pop();
      ++ans;
    }
    tank -= d;
    pos = A[i];
    q.push(B[i]);
  }
  printf("%d\n", ans);
}
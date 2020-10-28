#include <algorithm>
#include <fstream>
#include <stdio.h>
#include <utility>

#define MAX_N 100'000

using namespace std;

typedef pair<int, int> P;

int N, S[MAX_N]{}, T[MAX_N]{};
P V[MAX_N]{};

int main() {
  ifstream ifs("../testset/periodic_scheduling/test1.txt");
  ifs >> N;
  for (int i = 0; i < N; ++i) {
    ifs >> S[i];
  }
  for (int i = 0; i < N; ++i) {
    ifs >> T[i];
  }
  for (int i = 0; i < N; ++i) {
    V[i] = P(T[i], S[i]);
  }
  sort(V, V + N);

  int ans = 0;
  int t = 0;
  for (int i = 0; i < N; ++i) {
    if (t <= V[i].second) {
      ++ans;
      t = V[i].first;
    }
  }
  printf("%d\n", ans);
}
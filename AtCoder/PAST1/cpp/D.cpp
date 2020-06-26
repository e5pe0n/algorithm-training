#include <map>
#include <string>
#include <vector>

using namespace std;

void solve(vector<int> &V) {
  int N = V[0];
  vector<int> B(N, 0);

  for (int i = 1; i <= N; ++i) {
    B[V[i] - 1] += 1;
  }

  int x = 0;
  int y = 0;
  for (int i = 0; i < N; ++i) {
    if (B[i] == 0) {
      x = i + 1;
    } else if (B[i] == 2) {
      y = i + 1;
    }
  }

  if (x == 0) {
    printf("Correct\n");
  } else {
    printf("%d %d\n", y, x);
  }
}

int main() {
  map<string, vector<int>> cases{{"case1", vector<int>{6, 1, 5, 6, 3, 2, 6}},
                                 {"case2", vector<int>{7, 5, 4, 3, 2, 7, 6, 1}}};

  for (auto &[k, v] : cases) {
    printf("[%s]\n", k.c_str());
    solve(v);
    printf("\n");
  }
}

// [case1]
// 6 4

// [case2]
// Correct

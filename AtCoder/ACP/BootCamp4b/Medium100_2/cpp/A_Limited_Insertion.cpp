#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;

int N;
vector<int> B;
vector<int> res;

void solve() {
  while (B.size() > 0) {
    bool f = false;
    for (int j = B.size() - 1; j >= 0; --j) {
      if (B[j] == j) {
        B.erase(B.begin() + j);
        f = true;
        res.push_back(j);
        break;
      }
    }
    if (!f) {
      puts("-1");
      return;
    }
  }
  for (int i = res.size() - 1; i >= 0; --i) {
    printf("%d\n", res[i] + 1);
  }
}

int main() {
  cin >> N;
  B = vector<int>(N);
  for (int i = 0; i < N; ++i) {
    cin >> B[i];
    --B[i];
  }
  solve();
}
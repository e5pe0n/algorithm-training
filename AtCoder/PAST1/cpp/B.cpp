#include <math.h>
#include <stdio.h>
#include <vector>

using namespace std;

void solve(vector<int> &V) {
  int N = V[0];

  for (int i = 0; i < N - 1; ++i) {
    int diff = V[i + 2] - V[i + 1];
    if (diff == 0) {
      printf("stay\n");
    } else if (diff < 0) {
      printf("down %d\n", abs(diff));
    } else {
      printf("up %d\n", diff);
    }
  }
}

int main() {
  vector<int> v{10, 9, 10, 3, 100, 100, 90, 80, 10, 30, 10};
  solve(v);
}

// up 1
// down 7
// up 97
// stay
// down 10
// down 10
// down 70
// up 20
// down 20

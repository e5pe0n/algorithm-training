#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
  int A[8] = {10, 20, 30, 30, 20, 10, 10, 20};
  sort(A, A + 8); // 10, 10, 10, 20, 20, 20, 30, 30
  auto low = lower_bound(A, A + 8, 20);
  auto up = upper_bound(A, A + 8, 20);

  printf("low idx: %d, low val: %d\n", (int)(low - A), *low);
  printf("up idx: %d, up val: %d\n", (int)(up - A), *up);
  // low idx: 3, low val: 20
  // up idx: 6, up val: 30

  vector<int> V{10, 20, 30, 30, 20, 10, 10, 20};
  sort(V.begin(), V.end());
  auto _low = lower_bound(V.begin(), V.end(), 20);
  auto _up = upper_bound(V.begin(), V.end(), 20);

  printf("_low idx: %d, _low val: %d\n", (int)(_low - V.begin()), *_low);
  printf("_up idx: %d, _up val: %d\n", (int)(_up - V.begin()), *_up);
  // _low idx: 3, _low val: 20
  // _up idx: 6, _up val: 30
}
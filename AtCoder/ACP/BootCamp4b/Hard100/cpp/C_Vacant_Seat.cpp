#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int N;

int main() {
  setbuf(stdout, NULL);
  cin >> N;
  int left_idx = 0;
  int right_idx = N - 1;
  int mid_idx = (left_idx + right_idx) / 2;
  string left, mid, right;
  printf("%d\n", left_idx);
  cin >> left;
  printf("%d\n", right_idx);
  cin >> right;
  if (left == "Vacant" || right == "Vacant") {
    return 0;
  }
  while (true) {
    printf("%d\n", mid_idx);
    cin >> mid;
    if (mid == "Vacant") {
      return 0;
    } else if (((mid_idx - left_idx) % 2 == 0 && left != mid) ||
               ((mid_idx - left_idx) % 2 != 0 && left == mid)) {
      right_idx = mid_idx;
      right = mid;
      mid_idx = (left_idx + right_idx) / 2;
    } else {
      left_idx = mid_idx;
      left = mid;
      mid_idx = (left_idx + right_idx) / 2;
    }
  }
}
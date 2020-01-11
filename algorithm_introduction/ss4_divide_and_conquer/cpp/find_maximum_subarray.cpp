#include <cassert>
#include <iostream>
#include <vector>

#define assertm(exp, msg) assert(((void)msg, exp))

using namespace std;

const int INF = 1'000'000'000;

vector<int> find_max_crossing_subarray(int A[], int low_idx, int mid_idx, int high_idx) {
  int max_left_sum = -INF;
  int left_idx = mid_idx;
  int sum = 0;
  for (int i = mid_idx; i >= 0; --i) {
    sum += A[i];
    if (sum > max_left_sum) {
      max_left_sum = sum;
      left_idx = i;
    }
  }
  int max_right_sum = -INF;
  int right_idx = mid_idx + 1;
  sum = 0;
  for (int j = mid_idx + 1; j <= high_idx; ++j) {
    sum += A[j];
    if (sum > max_right_sum) {
      max_right_sum = sum;
      right_idx = j;
    }
  }
  vector<int> vec{left_idx, right_idx, max_left_sum + max_right_sum};
  return vec;
}

vector<int> find_maximum_subarray(int A[], int low_idx, int high_idx) {
  if (low_idx == high_idx) {
    vector<int> vec{low_idx, high_idx, A[low_idx]};
    return vec;
  } else {
    int mid_idx = (low_idx + high_idx) / 2;

    vector<int> left_res_vec;
    vector<int> right_res_vec;
    vector<int> cross_res_vec;

    left_res_vec = find_maximum_subarray(A, low_idx, mid_idx);
    right_res_vec = find_maximum_subarray(A, mid_idx + 1, high_idx);
    cross_res_vec = find_max_crossing_subarray(A, low_idx, mid_idx, high_idx);

    if (left_res_vec[2] > right_res_vec[2] & left_res_vec[2] > cross_res_vec[2]) {
      return left_res_vec;
    } else if (right_res_vec[2] > left_res_vec[2] & right_res_vec[2] > cross_res_vec[2]) {
      return right_res_vec;
    } else {
      return cross_res_vec;
    }
  }
}

int main() {
  int A[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
  int n_A = sizeof(A) / sizeof(*A);
  vector<int> res_vec(3, 0);

  cout << "A: [";
  for (size_t i = 0; i < n_A; ++i) {
    cout << A[i] << ", ";
  }
  cout << "]\n";

  res_vec = find_maximum_subarray(A, 0, n_A - 1);
  assertm(res_vec[0] == 7, "low_idx == 7");
  assertm(res_vec[1] == 10, "right_idx == 10");
  assertm(res_vec[2] == 43, "max_sum == 43");
  cout << "Clear" << endl;
}
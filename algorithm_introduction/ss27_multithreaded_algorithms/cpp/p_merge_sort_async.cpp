#include <algorithm>
#include <future>
#include <stdio.h>
#include <vector>

using namespace std;

int binary_search(int x, vector<int> &T, int p, int r) {
  int low = p;
  int high = max(p, r + 1);
  while (low < high) {
    int mid = (low + high) / 2;
    if (x <= T[mid]) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  return high;
}

void p_merge(vector<int> &T, int p1, int r1, int p2, int r2, vector<int> &A, int p3) {
  int n1 = r1 - p1 + 1;
  int n2 = r2 - p2 + 1;
  if (n1 < n2) {
    swap(n1, n2);
    swap(p1, p2);
    swap(r1, r2);
  }
  if (n1 == 0) {
    return;
  } else {
    int q1 = (r1 - p1) / 2;
    int q2 = binary_search(T[q1], ref(T), p2, r2);
    int q3 = p3 + (q1 - r1) + (q2 - r2);
    A[q3] = T[q1];
    future<void> fu = async(p_merge, ref(T), p1, q1 - 1, p2, q2 - 1, ref(A), p3);
    p_merge(ref(T), q1 + 1, r1, q2, r2, ref(A), q3 + 1);
    fu.get();
  }
}

void p_merge_sort(vector<int> &A, int p, int r, vector<int> &B, int s) {
  int n = r - p + 1;
  if (n == 1) {
    B[s] = A[p];
  } else {
    vector<int> T(n);
    int q = (p + r) / 2;
    int _q = r - p + 1;
    future<void> fu = async(p_merge_sort, ref(A), p, q, ref(T), s);
    p_merge_sort(ref(A), q + 1, r, T, _q + 1);
    fu.get();
    p_merge(ref(T), 0, _q, _q + 1, n - 1, ref(B), s);
  }
}

int main() {}
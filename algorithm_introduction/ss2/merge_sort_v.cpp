#include <iostream>
#include <vector>

using namespace std;

const int INF = 1'000'000'000;

void merge(vector<int>& vec, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  vector<int> left;
  for (int i = 0; i < n1; ++i) {
    left.emplace_back(vec[p + i]);
  }
  vector<int> right;
  for (int i = 0; i < n2; ++i) {
    right.emplace_back(vec[q + i + 1]);
  }

  left.emplace_back(INF);
  right.emplace_back(INF);

  int i = 0;
  int j = 0;
  int k = p;
  while (k <= r) {
    if (left[i] <= right[j]) {
      vec[k] = left[i++];
    } else {
      vec[k] = right[j++];
    }
    ++k;
  }
}

void merge_sort(vector<int>& vec, int p, int r) {
  if (r <= p) return;
  int q = (p + r) / 2;
  merge_sort(vec, p, q);
  merge_sort(vec, q + 1, r);
  merge(vec, p, q, r);
  return;
}

void display_vector(const vector<int> vec) {
  for (auto v : vec) {
    cout << v << ", ";
  }
  cout << endl;
}

int main() {
  vector<int> A{13, 15, 11, 14, 12};
  vector<int> B{13, 15, 11, 14, 12, 16};

  cout << "# A" << endl;
  cout << "before: ";
  display_vector(A);
  merge_sort(A, 0, A.size() - 1);
  cout << "after: ";
  display_vector(A);

  cout << "# B" << endl;
  cout << "before: ";
  display_vector(B);
  merge_sort(B, 0, B.size() - 1);
  cout << "after: ";
  display_vector(B);
}
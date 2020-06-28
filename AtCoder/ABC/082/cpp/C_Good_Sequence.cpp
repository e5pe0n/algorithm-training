#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  unordered_map<int, int> M;
  for (auto &a : A) {
    M[a] += 1;
  }

  int cnt = 0;
  for (auto &m : M) {
    if (m.first < m.second) {
      cnt += m.second - m.first;
    } else if (m.first > m.second) {
      cnt += m.second;
    }
  }
  printf("%d\n", cnt);
}
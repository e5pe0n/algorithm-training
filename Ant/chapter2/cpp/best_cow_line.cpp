#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

int N;
string S, T;

int main() {
  ifstream ifs("../testset/best_cow_line/test1.txt");
  ifs >> N >> S;
  int left_idx = 0;
  int right_idx = N - 1;
  while (left_idx <= right_idx) {
    bool left = false;
    for (int i = left_idx; left_idx + i <= right_idx; ++i) {
      if (S[left_idx + i] < S[right_idx - i]) {
        left = true;
        break;
      } else {
        left = false;
        break;
      }
    }
    if (left) {
      T += S[left_idx++];
    } else {
      T += S[right_idx--];
    }
  }
  printf("%s\n", T.c_str());
}
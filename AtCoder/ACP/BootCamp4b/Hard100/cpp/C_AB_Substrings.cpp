#include <iostream>
#include <stdio.h>
#include <string>

#define MAX_N 10'000

using namespace std;

string S[MAX_N]{};

int main() {
  int N;
  cin >> N;
  int cnt_A = 0;
  int cnt_B = 0;
  int cnt_B_A = 0;
  int cnt_AB = 0;
  for (int i = 0; i < N; ++i) {
    cin >> S[i];
    int n = S[i].size();
    for (int j = 0; j < n - 1; ++j) {
      if (S[i].substr(j, 2) == "AB") {
        ++cnt_AB;
      }
    }
    if (S[i][0] == 'B' && S[i][n - 1] == 'A') {
      ++cnt_B_A;
    } else if (S[i][0] == 'B') {
      ++cnt_B;
    } else if (S[i][n - 1] == 'A') {
      ++cnt_A;
    }
  }
  if (cnt_B_A > 0) {
    cnt_AB += cnt_B_A - 1;
    if (cnt_A > 0) {
      ++cnt_AB;
      --cnt_A;
    }
    if (cnt_B > 0) {
      ++cnt_AB;
      --cnt_B;
    }
  }
  cnt_AB += min(cnt_A, cnt_B);
  printf("%d\n", cnt_AB);
}

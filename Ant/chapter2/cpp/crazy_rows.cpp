#include <fstream>
#include <stdio.h>
#include <string>

#define MAX_N 40

using namespace std;

int N;
int a[MAX_N];

int main() {
  ifstream ifs("../testset/crazy_rows/test3.txt");
  ifs >> N;
  for (int i = 0; i < N; ++i) {
    string s;
    ifs >> s;
    a[i] = -1;
    for (int j = 0; j < N; ++j) {
      if (s[j] == '1') {
        a[i] = j;
      }
    }
  }
  int res = 0;
  for (int i = 0; i < N; ++i) {
    int pos = -1;
    // find j satisfying a[j] <= i from top of the rows in order
    for (int j = i; j < N; ++j) {
      if (a[j] <= i) {
        pos = j;
        break;
      }
    }
    for (int j = pos; j > i; --j) {
      swap(a[j - 1], a[j]);
      ++res;
    }
  }
  printf("%d\n", res);
}
#include <algorithm>
#include <fstream>
#include <map>
#include <set>
#include <stdio.h>

#define MAX_P 1'000'000

using namespace std;

int P;
int a[MAX_P];

int main() {
  ifstream ifs("../testset/jessicas_reading_problem/test2.txt");
  ifs >> P;
  set<int> all;
  for (int i = 0; i < P; ++i) {
    ifs >> a[i];
    all.insert(a[i]);
  }
  int n = all.size();
  int i = 0, j = 0, _n = 0;
  map<int, int> cnt;
  int res = P;
  for (;;) {
    while (j < P && _n < n) {
      if (cnt[a[j++]]++ == 0) {
        ++_n;
      }
    }
    if (_n < n) {
      break;
    }
    res = min(res, j - i);
    if (--cnt[a[i++]] == 0) {
      --_n;
    }
  }
  printf("%d\n", res);
}
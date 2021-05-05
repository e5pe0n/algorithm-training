#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

int longest_1_sequence_len(int n) {
  int prev_cnt = 0, curr_cnt = 0;
  bool found_0 = false;
  int res = 0;
  while (n > 0) {
    if (!(n & 1)) {
      res = max(res, prev_cnt + curr_cnt + 1);
      swap(prev_cnt, curr_cnt);
      curr_cnt = 0;
      found_0 = true;
    } else {
      ++curr_cnt;
    }
    n >>= 1;
  }
  res = max(res, prev_cnt + curr_cnt + found_0);
  return res;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  int n;
  ifs >> n;
  printf("%d\n\n", longest_1_sequence_len(n));
}

int main() {
  solve("../testcases/05_03/01.txt");
  solve("../testcases/05_03/02.txt");
  solve("../testcases/05_03/03.txt");
  solve("../testcases/05_03/04.txt");
}
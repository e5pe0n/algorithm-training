#include <bitset>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int bits = 24;

void draw_line(vector<bitset<bits>> &screen, int w, int x1, int x2, int y) {
  bitset<bits> zero(0);
  screen[y] |= (~zero >> x1) & (~zero << (w * 8 - 1 - x2));
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  int len, w, x1, x2, y;
  ifs >> len >> w >> x1 >> x2 >> y;
  vector<bitset<bits>> screen(len / w);
  draw_line(screen, w, x1, x2, y);
  for (auto &b : screen)
    cout << b << endl;
  puts("");
}

int main() {
  solve("../testcases/05_08/01.txt");
  solve("../testcases/05_08/02.txt");
  solve("../testcases/05_08/03.txt");
  solve("../testcases/05_08/04.txt");
}

// # ../testcases/05_08/01.txt
// 000000000000000000000000
// 000000000111110000000000
// 000000000000000000000000

// # ../testcases/05_08/02.txt
// 000000000000000000000000
// 000000001111111100000000
// 000000000000000000000000

// # ../testcases/05_08/03.txt
// 000000000000000000000000
// 000111111111111111111110
// 000000000000000000000000

// # ../testcases/05_08/04.txt
// 000000000000000000000000
// 000000000000000000000000
// 111111111111111111111111
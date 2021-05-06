#include <bitset>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void draw_line(vector<bitset<8>> &screen, int w, int x1, int x2, int y) {
  int _x1 = x1 / 8;
  int _x2 = x2 / 8;
  bitset<8> zero(0);
  bitset<8> left_mask = ~zero >> (x1 % 8);
  bitset<8> right_mask = ~zero << ((8 - (x2 + 1) % 8) % 8);
  bitset<8> mid_mask = ~zero;
  if (_x1 == _x2) {
    screen[w * y + _x1] |= left_mask & right_mask;
  } else {
    screen[w * y + _x1] |= left_mask;
    for (int j = _x1 + 1; j < _x2; ++j) {
      screen[w * y + j] |= mid_mask;
    }
    screen[w * y + _x2] |= right_mask;
  }
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  int len, w, x1, x2, y;
  ifs >> len >> w >> x1 >> x2 >> y;
  vector<bitset<8>> screen(len);
  draw_line(screen, w, x1, x2, y);
  for (int i = 0; i < screen.size(); ++i) {
    printf(
        "%s%c", screen[i].to_string().c_str(), (i + 1) % w == 0 ? '\n' : ' ');
  }
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
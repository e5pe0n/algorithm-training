// Answers are correct but TLE (Time Limit Exceeded)

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int M[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool f(string s, int i, int N, int x, int y, int _x, int _y, int direction) {
  while (i < N && s[i] == 'F') {
    _x += M[direction][0];
    _y += M[direction][1];
    ++i;
  }
  if (i >= N) {
    return _x == x && _y == y;
  } else {
    bool res0 = f(s, i + 1, N, x, y, _x, _y, (direction + 1) % 4);
    bool res1 = f(s, i + 1, N, x, y, _x, _y, (direction + 3) % 4);
    return res0 || res1;
  }
}

int main() {
  string s;
  cin >> s;
  int x, y;
  cin >> x >> y;

  if (f(s, 0, s.size(), x, y, 0, 0, 0)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}

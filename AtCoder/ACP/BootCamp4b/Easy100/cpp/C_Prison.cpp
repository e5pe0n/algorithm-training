#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int L = 1;
  int R = N;
  bool flg = true;
  for (int i = 0; i < M; ++i) {
    int _L, _R;
    cin >> _L >> _R;
    if (L <= _L && _R <= R) {
      L = _L;
      R = _R;
    } else if (_L <= L && R <= _R) {
      continue;
    } else if (L <= _L && _L <= R && R <= _R) {
      L = _L;
    } else if (_L <= L && L <= _R && _R <= R) {
      R = _R;
    } else {
      flg = false;
    }
  }
  if (flg) {
    printf("%d\n", R - L + 1);
  } else {
    printf("0\n");
  }
}
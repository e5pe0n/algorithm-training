#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string C[200];

int main() {
  int H, W;
  cin >> H >> W;
  for (int i = 0; i < 2 * H; i += 2) {
    cin >> C[i];
    C[i + 1] = C[i];
  }
  for (int i = 0; i < 2 * H; ++i) {
    printf("%s\n", C[i].c_str());
  }
}
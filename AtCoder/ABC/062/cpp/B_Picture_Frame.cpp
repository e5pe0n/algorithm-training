#include <iostream>
#include <stdio.h>
#include <string>

#define MAX_H 100

using namespace std;

string S[MAX_H];

int main() {
  int H, W;
  cin >> H >> W;
  printf("\n");
  for (int i = 0; i < H; ++i) {
    cin >> S[i];
  }
  for (int j = 0; j < W + 2; ++j) {
    printf("#");
  }
  printf("\n");
  for (int i = 0; i < H; ++i) {
    printf("#%s#\n", S[i].c_str());
  }
  for (int j = 0; j < W + 2; ++j) {
    printf("#");
  }
  printf("\n");
}
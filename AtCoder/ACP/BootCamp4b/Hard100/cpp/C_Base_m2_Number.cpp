#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>

using namespace std;

int N;

int main() {
  cin >> N;
  if (N == 0) {
    printf("0\n");
    return 0;
  }
  string ans = "";
  while (N != 0) {
    ans = to_string(abs(N % 2)) + ans;
    N = (N - abs(N % 2)) / (-2);
  }
  printf("%s\n", ans.c_str());
}
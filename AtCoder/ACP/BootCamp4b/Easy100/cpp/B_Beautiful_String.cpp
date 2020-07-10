#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int W[26]{};

int main() {
  string w;
  cin >> w;
  for (int i = 0; i < w.size(); ++i) {
    ++W[w[i] - 'a'];
  }
  for (int i = 0; i < 26; ++i) {
    if (W[i] % 2 != 0) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
}
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  int N;
  cin >> N;
  string n = to_string(N);
  int fN = 0;
  for (int i = 0; i < n.size(); ++i) {
    fN += n[i] - '0';
  }
  if (N % fN == 0) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}

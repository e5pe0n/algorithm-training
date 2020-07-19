#include <iostream>
#include <stdio.h>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<int, int> M{{1, 1}};
  printf("%d\n", M[1]);
}
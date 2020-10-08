#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

vector<int> A[2]{};

int main() {
  for (auto a : A[1]) {
    printf("%d ", a);
  }
  printf("\n");
}
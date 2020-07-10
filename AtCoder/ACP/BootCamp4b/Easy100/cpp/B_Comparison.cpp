#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string A, B;
  cin >> A >> B;
  if (A.size() > B.size()) {
    printf("GREATER\n");
  } else if (A.size() < B.size()) {
    printf("LESS\n");
  } else {
    for (int i = 0; i < A.size(); ++i) {
      if (A[i] < B[i]) {
        printf("LESS\n");
        return 0;
      } else if (A[i] > B[i]) {
        printf("GREATER\n");
        return 0;
      }
    }
    printf("EQUAL\n");
  }
}
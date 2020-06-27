#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string S;
  cin >> S;
  if (S[S.size() - 1] == 'T') {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
}
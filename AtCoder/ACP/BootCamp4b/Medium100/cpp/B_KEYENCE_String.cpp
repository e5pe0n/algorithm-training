#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string S;
  cin >> S;
  string _S = "keyence";
  int N = S.size();
  int _N = _S.size();
  for (int i = 0; i <= _N; ++i) {
    if (_S.substr(0, i) == S.substr(0, i) && _S.substr(i) == S.substr(N - _N + i)) {
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
}
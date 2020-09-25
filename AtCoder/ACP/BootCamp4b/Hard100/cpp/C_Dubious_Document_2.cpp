#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main() {
  string _S, T;
  cin >> _S >> T;

  int N = _S.size();
  int M = T.size();

  vector<string> canditates;

  for (int i = 0; i <= N - M; ++i) {
    if (_S[i] == '?' || _S[i] == T[0]) {
      string S = _S;
      int j = 0;
      for (j; j < M && i + j < N; ++j) {
        if (S[i + j] == '?') {
          S[i + j] = T[j];
        } else if (S[i + j] != T[j]) {
          break;
        }
      }
      if (j == M) {
        for (int k = 0; k < N; ++k) {
          if (S[k] == '?') {
            S[k] = 'a';
          }
        }
        canditates.push_back(S);
        continue;
      }
    }
  }
  if (canditates.empty()) {
    printf("UNRESTORABLE\n");
    return 0;
  }

  sort(canditates.begin(), canditates.end());
  printf("%s\n", canditates[0].c_str());
}
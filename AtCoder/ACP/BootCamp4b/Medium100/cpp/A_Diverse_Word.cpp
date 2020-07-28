#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int C[26]{};

int main() {
  string S;
  cin >> S;
  int N = S.size();
  if (N < 26) {
    for (int i = 0; i < N; ++i) {
      ++C[S[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
      if (C[i] == 0) {
        S += i + 'a';
        printf("%s\n", S.c_str());
        return 0;
      }
    }
  } else {
    vector<char> V{S[N - 1]};
    int i = N - 2;
    while (i >= 0) {
      for (int j = 0; j < V.size(); ++j) {
        if (S[i] < V[j]) {
          S = S.substr(0, i);
          S += V[j];
          printf("%s\n", S.c_str());
          return 0;
        }
      }
      V.push_back(S[i--]);
      sort(V.begin(), V.end());
    }
    printf("-1\n");
  }
}
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

vector<int> compute_prefix_function(string P) {
  int m = P.size();
  vector<int> Q(m, 0);
  int k = 0;
  for (int q = 1; q < m; ++q) {
    while (k > 0 && P[k] != P[q]) {
      k = Q[k];
    }
    if (P[k] == P[q]) {
      ++k;
    }
    Q[q] = k;
  }
  return Q;
}

void KMP_matcher(string T, string P) {
  int n = T.size();
  int m = P.size();
  vector<int> Q = compute_prefix_function(P);
  int q = 0;
  for (int i = 0; i < n; ++i) {
    while (q > 0 && P[q] != T[i]) {
      q = Q[q - 1];
    }
    if (P[q] == T[i]) {
      ++q;
    }
    if (q == m) {
      printf("Pattern occured at shift %d\n", i + 1 - m);
      q = Q[q - 1];
    }
  }
}

int main() {
  string T = "bacbababacabbcbab";
  string P = "ababaca";
  vector<int> Q = compute_prefix_function(P);
  printf("Q: [");
  for (auto q : Q) {
    printf("%d ", q);
  }
  printf("]\n");
  KMP_matcher(T, P);
}

// Q: [0 0 1 2 3 0 1 ]
// Pattern occured at shift 4
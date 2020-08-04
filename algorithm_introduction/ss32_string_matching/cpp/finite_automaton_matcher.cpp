#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> compute_transition_function(string P, vector<char> S) {
  int m = P.size();
  vector<vector<int>> D(S.size(), vector<int>(m + 1, 0));
  for (int q = 0; q <= m; ++q) {
    for (auto a : S) {
      string Pqa = P.substr(0, q);
      Pqa += a;
      string Pk = P;
      while (Pk.size() > 0 && Pk != Pqa.substr(max(0, (int)(Pqa.size() - Pk.size())), Pk.size())) {
        Pk.erase(Pk.end() - 1);
      }
      D[a - 'a'][q] = Pk.size();
    }
  }
  return D;
}

void finite_automaton_matcher(string T, vector<vector<int>> D, int m) {
  int n = T.size();
  int q = 0;
  for (int i = 0; i < n; ++i) {
    q = D[T[i] - 'a'][q];
    if (q == m) {
      printf("Pattern occured at shift %d\n", i + 1 - m);
    }
  }
}

int main() {
  string T = "abababacaba";
  string P = "ababaca";
  vector<char> S{'a', 'b', 'c'};
  vector<vector<int>> D = compute_transition_function(P, S);
  printf("transition function D:\n");
  for (auto d : D) {
    for (auto _d : d) {
      printf("%d ", _d);
    }
    printf("\n");
  }
  printf("\n");
  finite_automaton_matcher(T, D, P.size());
}

// transition function D:
// 1 1 3 1 5 1 7 1
// 0 2 0 4 0 4 0 2
// 0 0 0 0 0 6 0 0

// Pattern occured at shift 2
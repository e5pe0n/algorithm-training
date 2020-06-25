#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>

#define N 100

using namespace std;

vector<vector<int>> compute_transition_function(string P, vector<string> S) {
  int m = (int)P.size();
  vector<vector<int>> d(m, vector<int>((int)S.size()));
  string Pk = "";
  for (int q = 0; q <= m; ++q) {
    int k = min(m, q + 1);
    Pk += P[k - 1];
    for (auto s : S) {
      for (int k; k > 0; --k) {
        string _Pk = Pk;
        if (_Pk == P[q] + s)
      }
    }
  }
}

void finite_automaton_matcher(string T, vector<vector<int>> dlt, int m) {}

int main() {
  string P = "ababaca";
  string T = "abababacaba";

  vector<string> S{'a', 'b', 'c'};
  vector<vector<int>> d = compute_transition_function(P, S);

  finite_automaton_matcher(T, d, (int)P.size());
}
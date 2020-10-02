#include <set>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string s = "123123123";
  int N = s.size();
  set<string> S;
  for (int i = 0; i < N - 2; ++i) {
    for (int j = i + 1; j < N - 1; ++j) {
      for (int k = j + 1; k < N; ++k) {
        S.insert(string(1, s[i]) + string(1, s[j]) + string(1, s[k]));
      }
    }
  }
  printf("%d\n", (int)S.size());
  for (auto _s : S) {
    printf("%s ", _s.c_str());
  }
  printf("\n");
}
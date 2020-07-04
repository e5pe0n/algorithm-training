#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int res = 0;
  for (int i = 1; i <= N; ++i) {
    string s = to_string(i);
    int t = 0;
    for (int j = 0; j < s.size(); ++j) {
      t += s[j] - '0';
    }
    if (A <= t && t <= B) {
      res += i;
    }
  }
  printf("%d\n", res);
}

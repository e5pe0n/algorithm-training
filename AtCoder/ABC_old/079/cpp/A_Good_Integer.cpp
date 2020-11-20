#include <iostream>
#include <stdint.h>
#include <string>

using namespace std;

int main() {
  int N;
  cin >> N;
  string s = to_string(N);
  int cnt = 1;
  for (int i = 1; i < s.size(); ++i) {
    if (s[i] == s[i - 1]) {
      ++cnt;
      if (cnt == 3) {
        printf("Yes\n");
        return 0;
      }
    } else {
      cnt = 1;
    }
  }
  printf("No\n");
}
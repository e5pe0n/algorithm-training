#include <iostream>
#include <regex>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string S;
  cin >> S;
  regex rx(R"(^(dream|dreamer|erase|eraser)+?$)");
  if (regex_match(S, rx)) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
}
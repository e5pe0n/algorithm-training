#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string s = "abcde";
  s[2] = 2 + '0';
  printf("%s\n", s.c_str());
}
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string s = "abc";
  printf("%s\n", s.substr(-5, 5).c_str());
}
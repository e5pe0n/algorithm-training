#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string s = "aba";
  printf("%d\n", s.find("aa") == string::npos);
  printf("%d\n", s.find("a") != string::npos);
}
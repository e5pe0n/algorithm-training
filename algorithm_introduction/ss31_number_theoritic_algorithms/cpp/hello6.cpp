#include <iostream>
#include <string>

using namespace std;

int main() {
  int a = 10;
  int n = 1;
  cout << to_string(a & 1) << "\n";
  a = a >> 1;
  cout << to_string(a & 1) << "\n";
}
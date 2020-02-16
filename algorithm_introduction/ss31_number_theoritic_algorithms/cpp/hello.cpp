#include <bitset>
#include <iostream>
#include <string>

using namespace std;

int main() {
  bitset<4> b4(17);
  cout << b4.to_string() << endl;
}
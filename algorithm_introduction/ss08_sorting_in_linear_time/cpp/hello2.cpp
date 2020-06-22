#include <iostream>
#include <string>

using namespace std;

int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
int (*p_a)[3] = a;

int main() {
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      cout << to_string(p_a[i][j]) << ", ";
    }
  }
  cout << endl;

  int b[3] = {7, 8, 9};
  int *p_b = b;
  *p_a[0] = p_b;
}
#include <iostream>
#include <string>

using namespace std;

int a[2][3] = {{10, 11, 12}, {21, 22, 23}};
int b[2][3] = {{100, 101, 102}, {201, 202, 203}};

int main() {
  swap(a[0], b[0]);

  cout << "[";
  for (int i = 0; i < 2; ++i) {
    cout << "[";
    for (int j = 0; j < 3; ++j) {
      cout << to_string(b[i][j]) << ", ";
    }
    cout << "]";
  }
  cout << "]" << endl;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
  cout << "Hello" << endl;
  vector<int> vec(0);
  for (int i = 0; i < 10; ++i) {
    vec.push_back(i);
  }
}
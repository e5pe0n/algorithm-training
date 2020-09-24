#include <stdio.h>
#include <vector>

using namespace std;

int i = 0;

int _size(vector<int> v) {
  printf("%d\n", i++);
  return (int)v.size();
}

int main() {
  vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (int i = 0; i < _size(v); ++i) {
    v.pop_back();
  }
}

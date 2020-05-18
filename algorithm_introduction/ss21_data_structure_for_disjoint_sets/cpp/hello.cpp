#include <stdio.h>
#include <vector>

using namespace std;

int main() {
  vector<int> vec{10, 11, 12};

  for (int i = 0; i < vec.size(); ++i) {
    vector<int> _vec{100, 101, 102};
    vec = _vec;
  }

  for (int i = 0; i < vec.size(); ++i) {
    printf("%d, ", vec[i]);
  }
  printf("\n");
}
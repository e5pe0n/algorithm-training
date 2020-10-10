#include <map>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
  map<vector<int>, int> M;
  ++M[vector<int>{1, 2}];
  ++M[vector<int>{1, 2}];
  for (auto m : M) {
    printf("%d\n", m.second);
  }
}

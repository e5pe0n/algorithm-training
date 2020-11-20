#include <iostream>
#include <set>
#include <stdio.h>

using namespace std;

int main() {
  set<int> s{1, 1, 2, 3};
  for (auto &_s : s) {
    printf("%d, ", _s); // 1, 2, 3,
  }
  printf("\n");

  s.insert(4);
  s.insert(4);
  s.erase(2);
  if (s.count(1)) {
    printf("found 1\n"); // found 1
  } else {
    printf("not found 1\n");
  }
  if (s.count(2)) {
    printf("found 2\n");
  } else {
    printf("not found 2\n"); // not found 2
  }

  printf("s.empty(): %d\n", s.empty()); // 0

  printf("the least value: %d\n", *begin(s));    // 1
  printf("the largest value: %d\n", *rbegin(s)); // 4
}
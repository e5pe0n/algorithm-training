#include <climits>
#include <limits>
#include <stdio.h>

using namespace std;

int main() {
  printf("%d\n", numeric_limits<int>::max()); // 2147483647
  printf("%d\n", numeric_limits<int>::min()); // -2147483648

  printf("%e\n", numeric_limits<double>::max());    // 1.797693e+308
  printf("%e\n", numeric_limits<double>::min());    // 2.225074e-308
  printf("%e\n", numeric_limits<double>::lowest()); // -1.797693e+308
}
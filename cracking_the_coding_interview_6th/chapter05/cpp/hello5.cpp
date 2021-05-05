#include <string>
using namespace std;

int main() {
  int m = 1;
  m <<= 2;
  int n = 10;
  printf("%d\n", n & m);
}
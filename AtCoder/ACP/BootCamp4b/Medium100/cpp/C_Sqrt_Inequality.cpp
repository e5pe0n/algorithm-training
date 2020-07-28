#include <iostream>
#include <math.h>
#include <stdio.h>

typedef long long ll;

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int t = c - a - b;
  if (t > 0 && (ll)4 * a * b < (ll)t * t) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}
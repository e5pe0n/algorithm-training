#include <bits/stdc++.h>
using namespace std;

string S, T, U;
int A, B;

int main() {
  cin >> S >> T >> A >> B >> U;
  if (U == S) {
    printf("%d %d\n", A - 1, B);
  } else {
    printf("%d %d\n", A, B - 1);
  }
}
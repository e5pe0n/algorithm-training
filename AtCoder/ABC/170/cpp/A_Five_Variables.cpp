#include <bits/stdc++.h>
using namespace std;

int main() {
  for (int i = 0; i < 5; ++i) {
    string x;
    cin >> x;
    if (x == "0") {
      printf("%d\n", i + 1);
    }
  }
}
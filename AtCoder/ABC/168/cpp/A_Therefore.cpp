#include <bits/stdc++.h>
using namespace std;

string N;

int main() {
  cin >> N;
  int n = N[N.size() - 1] - '0';
  if (n == 2 || n == 4 || n == 5 || n == 7 || n == 9) {
    puts("hon");
  } else if (n == 0 || n == 1 || n == 6 || n == 8) {
    puts("pon");
  } else {
    puts("bon");
  }
}
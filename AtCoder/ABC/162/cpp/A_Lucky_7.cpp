#include <bits/stdc++.h>
using namespace std;

string N;

int main() {
  cin >> N;
  for (auto n : N) {
    if (n == '7') {
      puts("Yes");
      return 0;
    }
  }
  puts("No");
}
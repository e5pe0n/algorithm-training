#include <bits/stdc++.h>
using namespace std;

int K, A, B;

int main() {
  cin >> K >> A >> B;
  for (int i = A; i <= B; ++i) {
    if (i % K == 0) {
      puts("OK");
      return 0;
    }
  }
  puts("NG");
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll A, B;

int main() {
  cin >> A >> B;
  if (A <= B && B <= A * 6)
    puts("Yes");
  else
    puts("No");
}
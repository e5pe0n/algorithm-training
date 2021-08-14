#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N;

int main() {
  cin >> N;
  if (1 <= N && N <= 125)
    puts("4");
  else if (N <= 211)
    puts("6");
  else
    puts("8");
}
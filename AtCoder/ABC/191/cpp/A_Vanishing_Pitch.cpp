#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll V, T, S, D;

int main() {
  cin >> V >> T >> S >> D;
  if (V * T <= D && D <= V * S)
    puts("No");
  else
    puts("Yes");
}
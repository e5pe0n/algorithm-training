#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll K, X;

int main() {
  cin >> K >> X;
  if (500 * K >= X)
    puts("Yes");
  else
    puts("No");
}
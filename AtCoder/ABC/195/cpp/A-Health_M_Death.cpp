#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll M, H;

int main() {
  cin >> M >> H;
  if (H % M == 0)
    puts("Yes");
  else
    puts("No");
}
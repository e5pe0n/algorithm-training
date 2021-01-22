#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char A, B;

void solve() {
  if (A > B) swap(A, B);
  if (A <= B)
    puts(string(B - '0', A).c_str());
  else
    puts(string(A - '0', B).c_str());
}

int main() {
  cin >> A >> B;
  solve();
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;

void solve() {
  if (N == 0) {
    puts("0");
    return;
  }
  string res;
  while (N != 0) {
    res = to_string(abs(N % 2)) + res;
    N = N / (-2) + max(0LL, (N / -2) * (-2) - N);
  }
  printf("%s\n", res.c_str());
}

int main() {
  cin >> N;
  solve();
}
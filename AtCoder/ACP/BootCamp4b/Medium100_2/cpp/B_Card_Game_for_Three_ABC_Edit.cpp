#include <bits/stdc++.h>
using namespace std;

string S[3];
int idx[3];

void solve() {
  int prv = 0;
  int nxt = 0;
  while (true) {
    nxt = S[prv][idx[prv]++] - 'a';
    if (idx[nxt] >= S[nxt].size()) {
      printf("%c\n", 'A' + nxt);
      return;
    }
    swap(nxt, prv);
  }
}

int main() {
  for (int i = 0; i < 3; ++i) {
    cin >> S[i];
  }
  solve();
}
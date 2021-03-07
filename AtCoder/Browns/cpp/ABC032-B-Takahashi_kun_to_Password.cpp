#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;
ll K;

int main() {
  cin >> S >> K;
  set<string> res;
  for (ll i = 0; i + K <= S.size(); ++i) {
    res.insert(S.substr(i, K));
  }
  printf("%ld\n", res.size());
}
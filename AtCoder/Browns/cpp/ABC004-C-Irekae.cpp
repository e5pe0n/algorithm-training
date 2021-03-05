#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
string S = "123456";

int main() {
  cin >> N;
  N %= 30;
  for (ll i = 0; i < N; ++i) {
    swap(S[i % 5], S[i % 5 + 1]);
  }
  puts(S.c_str());
}
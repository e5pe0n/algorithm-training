#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll T, N;
string S1, S2, S3;

int main() {
  cin >> T;
  for (ll i = 0; i < T; ++i) {
    cin >> N >> S1 >> S2 >> S3;
    string res = string(N, '1') + string(N, '0') + string(1, '1');
    puts(res.c_str());
  }
}
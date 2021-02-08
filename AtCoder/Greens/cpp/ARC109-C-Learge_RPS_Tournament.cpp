#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char win[200][200];
ll N, K;
string S;

int main() {
  win['R']['R'] = win['R']['S'] = win['S']['R'] = 'R';
  win['S']['S'] = win['S']['P'] = win['P']['S'] = 'S';
  win['P']['P'] = win['P']['R'] = win['R']['P'] = 'P';
  cin >> N >> K >> S;
  while (K--) {
    const auto t = S + S;
    for (ll i = 0; i < N; ++i) {
      S[i] = win[t[i * 2]][t[i * 2 + 1]];
    }
  }
  printf("%c\n", S[0]);
}
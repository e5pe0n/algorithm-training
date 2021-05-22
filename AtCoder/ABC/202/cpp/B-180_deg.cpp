#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string S;

int main() {
  cin >> S;
  reverse(S.begin(), S.end());
  for (ll i = 0; i < S.size(); ++i) {
    if (S[i] == '0')
      S[i] = '0';
    else if (S[i] == '1')
      S[i] = '1';
    else if (S[i] == '6')
      S[i] = '9';
    else if (S[i] == '8')
      S[i] = '8';
    else if (S[i] == '9')
      S[i] = '6';
  }
  cout << S << endl;
}
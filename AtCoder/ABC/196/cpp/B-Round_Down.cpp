#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string X;

int main() {
  cin >> X;
  string res;
  ll i = 0;
  while (i < X.size() && X[i] != '.')
    res += X[i++];
  puts(res.c_str());
}
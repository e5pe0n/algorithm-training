#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;

int main() {
  cin >> S;
  puts((S.substr(1) + S[0]).c_str());
}
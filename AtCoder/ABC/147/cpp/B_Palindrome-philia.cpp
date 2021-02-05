#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;

int main() {
  cin >> S;
  ll left = 0;
  ll right = S.size() - 1;
  ll res = 0;
  while (left < right) {
    if (S[left++] != S[right--]) ++res;
  }
  printf("%lld\n", res);
}
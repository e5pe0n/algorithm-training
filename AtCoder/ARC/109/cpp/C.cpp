#include <bits/stdc++.h>
#define MAX_n 100
using namespace std;
typedef long long ll;

const char h[] = {'R', 'P', 'S'};

int n, k;
string s;
int hands[MAX_n];

ll mod_pow(string s) {
  ll res = 1;
  ll x = 2;
  for (int i = s.size() - 1; i >= 0; --i) {
    if (s[i] == '1') {
      res = (res * x) % n;
    }
    x = (x * 2) % n;
  }
  return res;
}

int judge(int left, int right) {
  int diff = (right - left + 3) % 3;
  if (diff == 0 || diff == 1) {
    return left;
  }
  if (diff == 2) {
    return right;
  }
}

char f(int _k, string _s) {
  printf("%d\n", _k);
  if (_k == 0) {
    return hands[mod_pow(s)];
  }
  int left = f(_k - 1, _s + '0');
  int right = f(_k - 1, _s + '1');
  int res = judge(left, right);
  return res;
}

void solve() { printf("%c\n", h[f(k, "")]); }

int main() {
  cin >> n >> k >> s;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R') {
      hands[i] = 0;
    } else if (s[i] == 'P') {
      hands[i] = 1;
    } else if (s[i] == 'S') {
      hands[i] = 2;
    }
  }
  solve();
}
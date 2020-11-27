#include <bits/stdc++.h>
#define MAX_N 1'000'000'000'000'001
using namespace std;
typedef long long ll;

ll N;

void solve() {
  vector<int> v;
  --N;
  while (N >= 0) {
    v.push_back(N % 26);
    N = N / 26 - 1;
  }
  string res;
  for (int i = v.size() - 1; i >= 0; --i) {
    res += v[i] + 'a';
  }
  printf("%s\n", res.c_str());
}

int main() {
  cin >> N;
  solve();
}
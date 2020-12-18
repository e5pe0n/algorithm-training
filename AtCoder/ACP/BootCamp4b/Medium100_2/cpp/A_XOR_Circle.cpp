#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

void solve() {
  map<ll, ll> cnt;
  for (int i = 0; i < N; ++i) {
    ++cnt[A[i]];
  }
  int n = cnt.size();
  if (n == 1 && cnt[0] == N) {
    puts("Yes");
    return;
  }
  if (N % 3 != 0) {
    puts("No");
    return;
  }
  if (n == 2 && (N - cnt[0]) % 2 == 0 && (N - cnt[0]) <= 2 * cnt[0]) {
    puts("Yes");
    return;
  }
  if (n == 3) {
    vector<ll> V;
    for (auto p : cnt) {
      if (p.second != N / 3) {
        puts("No");
        return;
      }
      V.push_back(p.first);
    }
    for (int i = 0; i < 3; ++i) {
      if ((V[i] ^ V[(i + 2) % 3]) != V[(i + 1) % 3]) {
        puts("No");
        return;
      }
    }
    puts("Yes");
    return;
  }
  puts("No");
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}
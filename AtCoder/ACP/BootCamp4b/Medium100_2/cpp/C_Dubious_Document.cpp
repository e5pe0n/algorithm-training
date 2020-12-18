#include <bits/stdc++.h>
#define MAX_N 50
#define INF 1'000'000'000
using namespace std;

int N;
string S[MAX_N];
int cnt1[26];
int cnt2[26];

void solve() {
  fill(cnt2, cnt2 + 26, INF);
  for (int i = 0; i < N; ++i) {
    fill(cnt1, cnt1 + 26, 0);
    for (auto s : S[i]) {
      ++cnt1[s - 'a'];
    }
    for (int j = 0; j < 26; ++j) {
      cnt2[j] = min(cnt2[j], cnt1[j]);
    }
  }
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < cnt2[i]; ++j) {
      printf("%c", i + 'a');
    }
  }
  printf("\n");
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> S[i];
  }
  solve();
}
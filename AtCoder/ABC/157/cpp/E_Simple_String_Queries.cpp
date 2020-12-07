#include <bits/stdc++.h>
#define MAX_Q 20000
#define MAX_N 500'000
using namespace std;

int N, Q;
string S;
int T[MAX_Q], I[MAX_Q], L[MAX_Q], R[MAX_Q];
char C[MAX_Q];
set<int> A[26];

void solve() {
  for (int i = 0; i < N; ++i) {
    A[S[i] - 'a'].insert(i);
  }
  for (int q = 0; q < Q; ++q) {
    if (T[q] == 1) {
      int i = I[q];
      char c = C[q];
      A[S[i] - 'a'].erase(i);
      S[i] = c;
      A[c - 'a'].insert(i);
    } else {
      int l = L[q];
      int r = R[q];
      int cnt = 0;
      for (int j = 0; j < 26; ++j) {
        auto left = A[j].lower_bound(l);
        if (left != A[j].end() && *left <= r) {
          ++cnt;
        }
      }
      printf("%d\n", cnt);
    }
  }
}

int main() {
  cin >> N >> S >> Q;
  for (int i = 0; i < Q; ++i) {
    cin >> T[i];
    if (T[i] == 1) {
      cin >> I[i] >> C[i];
      --I[i];
    } else {
      cin >> L[i] >> R[i];
      --L[i];
      --R[i];
    }
  }
  solve();
}
#include <bits/stdc++.h>
#define MAX_N 500'000
using namespace std;

int N, Q;
int dat[26][1 << 20];
string S;

void update(int k, char c, int n, int offset) {
  k += offset;
  dat[c - 'a'][k] = n;
  while (k > 0) {
    k = (k - 1) / 2;
    dat[c - 'a'][k] = dat[c - 'a'][k * 2 + 1] + dat[c - 'a'][k * 2 + 2];
  }
}

int query(char c, int l, int r, int k, int left, int right) {
  if (right <= l || r <= left) {
    return 0;
  }
  if (l <= left && right <= r) {
    return dat[c - 'a'][k];
  } else {
    int nl = query(c, l, r, k * 2 + 1, left, (left + right) / 2);
    int nr = query(c, l, r, k * 2 + 2, (left + right) / 2, right);
    return nl + nr;
  }
}

int main() {
  cin >> N >> S >> Q;
  int offset = 1;
  while (offset < N) {
    offset *= 2;
  }
  --offset;
  for (int i = 0; i < N; ++i) {
    update(i, S[i], 1, offset);
  }
  for (int q = 0; q < Q; ++q) {
    int t;
    cin >> t;
    if (t == 1) {
      int i;
      char c;
      cin >> i >> c;
      --i;
      update(i, S[i], 0, offset);
      S[i] = c;
      update(i, c, 1, offset);
    } else {
      int l, r;
      cin >> l >> r;
      int cnt = 0;
      for (char c = 'a'; c <= 'z'; ++c) {
        int v = query(c, l - 1, r, 0, 0, offset + 1);
        if (v > 0) {
          ++cnt;
        }
      }
      printf("%d\n", cnt);
    }
  }
}
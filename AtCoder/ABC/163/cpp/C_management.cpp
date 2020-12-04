#include <bits/stdc++.h>
#define MAX_N 200'000
using namespace std;

int N, A;
int cnt[MAX_N];

int main() {
  cin >> N;
  for (int i = 1; i < N; ++i) {
    cin >> A;
    ++cnt[A - 1];
  }
  for (int i = 0; i < N; ++i) {
    printf("%d\n", cnt[i]);
  }
}
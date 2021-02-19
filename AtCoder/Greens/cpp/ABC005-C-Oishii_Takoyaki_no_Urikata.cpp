#include <bits/stdc++.h>
#define MAX_N 100
#define MAX_M 100
using namespace std;
typedef long long ll;

ll T, N, M;
ll A[MAX_N];
ll B[MAX_M];

int main() {
  cin >> T >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  cin >> M;
  for (ll i = 0; i < M; ++i) {
    cin >> B[i];
  }
  ll i = 0;
  for (ll j = 0; j < M; ++j) {
    while (i < N && A[i] + T < B[j])
      ++i;
    if (i >= N || B[j] < A[i]) {
      puts("no");
      return 0;
    }
    ++i;
  }
  puts("yes");
}
#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll N;
ll A[MAX_N];

void solve() {
  sort(A, A + N);
  ll sum = A[0];
  ll res = 0;
  for (int i = 1; i < N; ++i) {
    if (sum * 2 >= A[i]) {
      ++res;
    } else {
      res = 0;
    }
    sum += A[i];
  }
  printf("%lld\n", res + 1);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}
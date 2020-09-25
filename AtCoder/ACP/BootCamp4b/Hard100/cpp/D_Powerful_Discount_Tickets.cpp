#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>

#define MAX_N 100'000

using namespace std;

typedef long long ll;

int main() {
  int N, M;
  cin >> N >> M;
  priority_queue<int, vector<int>, less<vector<int>::value_type>> A;
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    A.push(a);
  }

  for (int i = 0; i < M; ++i) {
    int a = A.top();
    A.pop();
    a = a / 2;
    A.push(a);
  }

  ll ans = 0;
  while (!A.empty()) {
    ll a = A.top();
    A.pop();
    ans += a;
  }
  printf("%lld\n", ans);
}
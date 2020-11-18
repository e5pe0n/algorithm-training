#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>

#define MAX_N 1'000'000

using namespace std;

int N;
int A[MAX_N];
bool used[MAX_N + 1];

vector<int> prime_factorize(int n) {
  vector<int> res;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i != 0) {
      continue;
    }
    while (n % i == 0) {
      n /= i;
    }
    res.push_back(i);
  }
  if (n != 1) {
    res.push_back(n);
  }
  return res;
}

int solve() {
  sort(A, A + N);
  int res = 0;
  for (int i = 0; i < N; ++i) {
    vector<int> V = prime_factorize(A[i]);
    for (int j = 0; j < V.size(); ++j) {
      int v = V[j];
      if (used[v]) {
        res = 2;
        break;
      }
      used[v] = true;
      for (int k = v * 2; k <= A[N - 1]; k += v) {
        used[v] = true;
      }
    }
    if (res == 2) {
      break;
    }
  }
  if (res == 0) {
    return res;
  }
  vector<int> _V = prime_factorize(A[0]);
  int cnt = 0;
  for (int j = 0; j < _V.size(); ++j) {
    for (int i = 0; i < N; ++i) {
      if (A[i] % _V[j] != 0) {
        ++cnt;
        break;
      }
    }
  }
  return cnt == _V.size() ? 1 : 2;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  int res = solve();
  if (res == 0) {
    printf("pairwise coprime\n");
  } else if (res == 1) {
    printf("setwise coprime\n");
  } else {
    printf("not coprime\n");
  }
}
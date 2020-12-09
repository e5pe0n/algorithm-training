#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;

int N;
int A[MAX_N];

void solve() {
  bool f = true;
  for (int i = 0; i < N; ++i) {
    int a = A[i];
    if (a % 2 == 0 && a % 3 != 0 && a % 5 != 0) {
      f = false;
    }
  }
  if (f) {
    puts("APPROVED");
  } else {
    puts("DENIED");
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  solve();
}
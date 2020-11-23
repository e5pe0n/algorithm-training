#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;

int N;
int L[MAX_N];

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> L[i];
  }
  int res = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      for (int k = j + 1; k < N; ++k) {
        if (L[i] != L[j] && L[j] != L[k] && L[k] != L[i] && L[i] + L[j] > L[k] && L[j] + L[k] > L[i] &&
            L[k] + L[i] > L[j]) {
          ++res;
        }
      }
    }
  }
  printf("%d\n", res);
}
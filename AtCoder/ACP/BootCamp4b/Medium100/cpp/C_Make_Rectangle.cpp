#include <algorithm>
#include <iostream>
#include <map>
#include <stdio.h>

typedef long long ll;

using namespace std;

int main() {
  int N;
  cin >> N;
  map<int, int> M;
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    ++M[a];
  }
  int a = 0;
  int b = 0;
  for (auto it = M.rbegin(); it != M.rend(); ++it) {
    if (it->second >= 2) {
      if (a == 0) {
        if (it->second >= 4) {
          a = it->first;
          b = it->first;
          break;
        } else {
          a = it->first;
        }
      } else {
        b = it->first;
        break;
      }
    }
  }
  printf("%lld\n", (ll)a * b);
}
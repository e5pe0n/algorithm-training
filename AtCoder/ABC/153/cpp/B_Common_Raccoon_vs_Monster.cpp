#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;
typedef long long ll;

ll H, N;

int main() {
  cin >> H >> N;
  for (int i = 0; i < N; ++i) {
    ll A;
    cin >> A;
    H -= A;
  }
  if (H <= 0) {
    puts("Yes");
  } else {
    puts("No");
  }
}
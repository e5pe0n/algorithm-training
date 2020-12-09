#include <bits/stdc++.h>
using namespace std;

int N[3];

int main() {
  for (int i = 0; i < 3; ++i) {
    cin >> N[i];
  }
  sort(N, N + 3);
  if ((N[0] == N[1] && N[1] != N[2]) || (N[0] != N[1] && N[1] == N[2])) {
    puts("Yes");
  } else {
    puts("No");
  }
}
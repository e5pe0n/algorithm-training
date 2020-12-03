#include <bits/stdc++.h>
using namespace std;

int S, W;

int main() {
  cin >> S >> W;
  if (W >= S) {
    puts("unsafe");
  } else {
    puts("safe");
  }
}
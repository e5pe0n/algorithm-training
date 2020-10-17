#include <iostream>
#include <stdio.h>
#include <string>

#define MAX_N 100'000

typedef long long ll;

using namespace std;

int N;

int main() {
  cin >> N;
  string ans = "second";
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    if (a % 2 != 0) {
      ans = "first";
    }
  }
  printf("%s\n", ans.c_str());
}
#include <bits/stdc++.h>
#define MAX_N 100'000
using namespace std;

int N;

int main() {
  cin >> N;
  map<string, int> cnt;
  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    ++cnt[s];
  }
  printf("AC x %d\n", cnt["AC"]);
  printf("WA x %d\n", cnt["WA"]);
  printf("TLE x %d\n", cnt["TLE"]);
  printf("RE x %d\n", cnt["RE"]);
}
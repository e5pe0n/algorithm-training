#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
  cin >> N;
  map<string, int> cnt;
  for (int i = 0; i < N; ++i) {
    string S;
    cin >> S;
    ++cnt[S];
  }
  int max_cnt = 0;
  for (auto p : cnt) {
    max_cnt = max(max_cnt, p.second);
  }
  for (auto p : cnt) {
    if (p.second == max_cnt) {
      puts(p.first.c_str());
    }
  }
}
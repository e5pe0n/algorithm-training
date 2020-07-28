#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>

typedef long long ll;

using namespace std;

int main() {
  string S;
  int K;
  cin >> S >> K;
  int N = S.size();
  int left = 1;
  while (left < N && S[0] == S[left]) {
    ++left;
  }
  int right = 0;
  while (N - 1 - right && S[0] == S[N - 1 - right]) {
    ++right;
  }
  S = S + S;
  ll cnt = 0;
  for (int i = 0; i < S.size() - 1; ++i) {
    if (S[i + 1] == S[i]) {
      S[i + 1] = 'A';
      ++cnt;
    }
  }
  printf("%lld\n", cnt);
  if (left + right < N && left % 2 != 0 && right % 2 != 0) {
    printf("%lld\n", max(0LL, (cnt + 1) * (K / 2) + ((cnt + 1) / 2) * (K % 2 != 0) - 1));
  } else {
    printf("%lld\n", cnt * (K / 2) + (cnt / 2) * (K % 2 != 0));
  }
}

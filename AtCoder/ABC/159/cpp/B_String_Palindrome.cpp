#include <bits/stdc++.h>
using namespace std;

string S;

bool is_palindrome(string s, int left, int right) {
  while (left <= right) {
    if (s[left] != s[right]) {
      return false;
    }
    ++left;
    --right;
  }
  return true;
}

int main() {
  cin >> S;
  int N = S.size();
  bool res = is_palindrome(S, 0, N - 1) && is_palindrome(S, 0, (N - 1) / 2 - 1) &&
             is_palindrome(S, (N + 3) / 2 - 1, N - 1);
  if (res) {
    puts("Yes");
  } else {
    puts("No");
  }
}
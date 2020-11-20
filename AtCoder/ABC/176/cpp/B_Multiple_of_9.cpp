#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
typedef long long ll;

string N;

int main() {
  cin >> N;
  ll res = 0;
  for (int i = 0; i < N.size(); ++i) {
    res += N[i] - '0';
  }
  if (res % 9 == 0) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}
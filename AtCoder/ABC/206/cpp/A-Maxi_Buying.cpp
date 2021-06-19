#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N;

int main() {
  cin >> N;
  ll res = 1.08 * N;
  if (res < 206)
    puts("Yay!");
  else if (res == 206)
    puts("so-so");
  else
    puts(":(");
}
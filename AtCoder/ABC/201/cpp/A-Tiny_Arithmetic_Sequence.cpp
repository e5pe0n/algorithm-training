#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll A[3];

int main() {
  cin >> A[0] >> A[1] >> A[2];
  sort(A, A + 3);
  if (A[0] - A[1] == A[1] - A[2])
    puts("Yes");
  else
    puts("No");
}
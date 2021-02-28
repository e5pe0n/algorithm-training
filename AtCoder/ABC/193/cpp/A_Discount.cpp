#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A, B;

int main() {
  cin >> A >> B;
  printf("%.3f\n", (double)(A - B) / A * 100);
}
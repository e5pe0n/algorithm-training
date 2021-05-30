#include <iostream>
#include <string>
using namespace std;
using ll = long long;

void print_parens(string pre, ll left, ll right) {
  if (left == 0 && right == 0) {
    cout << pre << endl;
    return;
  }
  if (left > 0) print_parens(pre + "(", left - 1, right);
  if (left < right) print_parens(pre + ")", left, right - 1);
}

void solve(const ll n) {
  cout << "# " << n << endl;
  print_parens("", n, n);
  cout << endl;
}

int main() {
  solve(3);
}

// # 3
// ((()))
// (()())
// (())()
// ()(())
// ()()()
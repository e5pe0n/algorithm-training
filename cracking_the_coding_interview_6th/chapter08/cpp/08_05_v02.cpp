// Cracking the Coding Interview p.352
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
using ll = long long;

ll _mul(ll smaller, ll bigger) {
  if (smaller == 0) return 0;
  if (smaller == 1) return bigger;
  ll s = smaller >> 1;
  ll half = _mul(s, bigger);
  if (smaller % 2 == 0)
    return half + half;
  else
    return half + half + bigger;
}

ll mul(ll n, ll m) {
  if (n > m) swap(n, m);
  return _mul(n, m);
}

void solve(const string &fp) {
  cout << "# " << fp << endl;
  ifstream ifs(fp);
  ll n, m;
  ifs >> n >> m;
  cout << mul(n, m) << "\n" << endl;
}

int main() {
  solve("../testcases/08_05/01.txt");
  solve("../testcases/08_05/02.txt");
}

// # ../testcases/08_05/01.txt
// 15

// # ../testcases/08_05/02.txt
// 50

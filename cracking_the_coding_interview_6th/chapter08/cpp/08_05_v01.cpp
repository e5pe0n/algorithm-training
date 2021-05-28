#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

ll mul(ll n, ll m) {
  if (n < m) swap(n, m);
  ll res = 0;
  while (m > 0) {
    if (m & 1) res += n;
    m >>= 1;
    n <<= 1;
  }
  return res;
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
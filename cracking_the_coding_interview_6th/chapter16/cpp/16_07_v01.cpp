#include <fstream>
#include <string>
using namespace std;
using ll = long long;

ll ma(const ll n, const ll m) {
  // m + n or m - n may overflow
  ll c = m + n;
  ll d = abs(m - n);
  return (c + d) / 2;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  ll n, m;
  ifs >> n >> m;
  printf("%lld\n\n", ma(n, m));
}

int main() {
  solve("../testcases/16_07/01.txt");
  solve("../testcases/16_07/02.txt");
  solve("../testcases/16_07/03.txt");
  solve("../testcases/16_07/04.txt");
  solve("../testcases/16_07/05.txt");
  solve("../testcases/16_07/06.txt");
  solve("../testcases/16_07/07.txt");
}

// # ../testcases/16_07/01.txt
// 2

// # ../testcases/16_07/02.txt
// 3

// # ../testcases/16_07/03.txt
// 1

// # ../testcases/16_07/04.txt
// 1

// # ../testcases/16_07/05.txt
// 2

// # ../testcases/16_07/06.txt
// -3

// # ../testcases/16_07/07.txt
// -2

#include <fstream>
#include <string>
using namespace std;
using ll = long long;

ll flip(ll bit) {
  return 1LL ^ bit;
}

ll sign(ll n) {
  return flip((n >> 63) & 1LL);
}

ll ma(const ll n, const ll m) {
  ll d = n - m;

  ll sn = sign(n);
  ll sm = sign(m);
  ll sd = sign(d);

  ll use_sign_of_n = sn ^ sm;
  ll use_sign_of_d = flip(sn ^ sm);
  ll k = use_sign_of_n * sn + use_sign_of_d * sd;
  ll q = flip(k);

  return n * k + m * q;
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
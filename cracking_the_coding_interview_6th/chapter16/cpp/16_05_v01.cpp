#include <fstream>
#include <string>
using namespace std;
using ll = long long;

ll cnt_trailing_zeros(ll n) {
  ll res = 0;
  while (n > 0) {
    res += n / 5;
    n /= 5;
  }
  return res;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  ll n;
  ifs >> n;
  printf("%lld: %lld\n\n", n, cnt_trailing_zeros(n));
}

int main() {
  solve("../testcases/16_05/01.txt");
  solve("../testcases/16_05/02.txt");
  solve("../testcases/16_05/03.txt");
  solve("../testcases/16_05/04.txt");
  solve("../testcases/16_05/05.txt");
}

// # ../testcases/16_05/01.txt
// 10: 2

// # ../testcases/16_05/02.txt
// 50: 12

// # ../testcases/16_05/03.txt
// 100: 24

// # ../testcases/16_05/04.txt
// 500: 124

// # ../testcases/16_05/05.txt
// 50000: 12499

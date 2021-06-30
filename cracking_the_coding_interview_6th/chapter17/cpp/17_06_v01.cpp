// Cracking the Coding Interview p.540
#include <fstream>
#include <math.h>
#include <string>
using namespace std;
using ll = long long;

ll cnt_2s_at_digit(ll n, ll d) {
  ll power_of_10 = pow(10, d);
  ll next_power_of_10 = power_of_10 * 10;
  ll right = n % power_of_10;

  ll round_down = n - n % next_power_of_10;
  ll round_up = round_down + next_power_of_10;

  ll digit = (n / power_of_10) % 10;
  if (digit < 2)
    return round_down / 10;
  else if (digit == 2)
    return round_down / 10 + right + 1;
  else
    return round_up / 10;
}

ll cnt_2s(ll n) {
  ll cnt = 0;
  for (ll i = 0; i < to_string(n).size(); ++i) {
    cnt += cnt_2s_at_digit(n, i);
  }
  return cnt;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  ll n;
  ifs >> n;
  ll res = cnt_2s(n);
  printf("%lld\n", res);
  puts("");
}

int main() {
  solve("../testcases/17_06/01.txt");
  solve("../testcases/17_06/02.txt");
  solve("../testcases/17_06/03.txt");
}

// # ../testcases/17_06/01.txt
// 9

// # ../testcases/17_06/02.txt
// 300

// # ../testcases/17_06/03.txt
// 4543901

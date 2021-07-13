// Cracking the Coding Interview p.592
#include <fstream>
#include <math.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

pll solve_equation(ll r1, ll r2) {
  ll a = 2;
  ll b = -2 * r1;
  ll c = r1 * r1 - r2;

  double p1 = -b;
  double p2 = sqrt(b * b - 4 * a * c);
  double p3 = 2 * a;

  ll sol1 = (ll)((p1 + p2) / p3);
  ll sol2 = r1 - sol1;
  return {sol1, sol2};
}

ll square_sum(ll n, ll power) {
  ll sum = 0;
  for (ll i = 1; i <= n; ++i) {
    sum += (ll)pow(i, power);
  }
  return sum;
}

pll missing_two(const vector<ll> &arr) {
  ll max_value = arr.size() + 2;
  ll rem_square = square_sum(max_value, 2);
  ll rem_one = max_value * (max_value + 1) / 2;
  for (auto v : arr) {
    rem_square -= v * v;
    rem_one -= v;
  }
  return solve_equation(rem_one, rem_square);
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  ll n, m;
  ifs >> n >> m;
  vector<ll> arr(m);
  for (ll i = 0; i < m; ++i) {
    ifs >> arr[i];
  }
  auto [x, y] = missing_two(arr);
  printf("%lld %lld\n", x, y);
  puts("");
}

int main() {
  solve("../testcases/17_19/01.txt");
  solve("../testcases/17_19/02.txt");
}

// # ../testcases/17_19/01.txt
// 9 3

// # ../testcases/17_19/02.txt
// 16 13

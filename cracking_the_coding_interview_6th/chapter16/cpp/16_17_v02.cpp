#include <fstream>
#include <limits>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll MIN = numeric_limits<ll>::min();

struct SumRange {
  ll sum = 0, left_idx = 0, right_idx = 0;
};

SumRange _max_sum_cross(const vector<ll> &v, ll low, ll mid, ll high) {
  ll left_sum = MIN;
  ll sum = 0;
  ll max_left_idx = 0;
  for (ll i = mid; i >= 0; --i) {
    sum += v[i];
    if (sum > left_sum) {
      left_sum = sum;
      max_left_idx = i;
    }
  }
  ll right_sum = MIN;
  sum = 0;
  ll max_right_idx = 0;
  for (ll i = mid + 1; i <= high; ++i) {
    sum += v[i];
    if (sum > right_sum) {
      right_sum = sum;
      max_right_idx = i;
    }
  }
  return SumRange{left_sum + right_sum, max_left_idx, max_right_idx};
}

SumRange _max_sum(const vector<ll> &v, ll low, ll high) {
  if (high == low) return SumRange{v[low], low, low};
  ll mid = (low + high) / 2;
  auto left = _max_sum(v, low, mid);
  auto right = _max_sum(v, min(mid + 1, high), high);
  auto cross = _max_sum_cross(v, low, mid, high);
  if (left.sum >= right.sum && left.sum >= cross.sum)
    return left;
  else if (right.sum >= left.sum && right.sum >= cross.sum)
    return right;
  else
    return cross;
}

ll max_sum(const vector<ll> &v) {
  auto res = _max_sum(v, 0, v.size() - 1);
  return res.sum;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  ll n;
  ifs >> n;
  vector<ll> v(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> v[i];
  }
  printf("%lld\n", max_sum(v));
  puts("");
}

int main() {
  solve("../testcases/16_17/01.txt");
  solve("../testcases/16_17/02.txt");
  solve("../testcases/16_17/03.txt");
}

// # ../testcases/16_17/01.txt
// 5

// # ../testcases/16_17/02.txt
// 192

// # ../testcases/16_17/03.txt
// 225

// Cracking the Coding Interview p.569
// O(n), only for array having distinct elements
#include <fstream>
#include <limits>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

default_random_engine generator;

ll max_elem(const vector<ll> &v, const ll left, const ll right) {
  ll ma = numeric_limits<ll>::max();
  for (ll i = left; i <= right; ++i) {
    ma = max(ma, v[i]);
  }
  return ma;
}

ll rnd_int_in_rng(ll mi, ll ma) {
  uniform_int_distribution<ll> dist{mi, ma};
  return dist(generator);
}

ll partition(vector<ll> &v, ll left, ll right, ll pivot) {
  while (left <= right) {
    if (v[left] > pivot) {
      swap(v[left], v[right]);
      --right;
    } else if (v[right] <= pivot) {
      swap(v[left], v[right]);
      ++left;
    } else {
      ++left;
      --right;
    }
  }
  return left - 1;
}

ll get_elem_by_rnk(vector<ll> &v, ll left, ll right, ll rnk) {
  ll pivot = v[rnd_int_in_rng(left, right)];
  ll left_end = partition(v, left, right, pivot);
  ll left_size = left_end - left + 1;
  if (rnk == left_size - 1) {
    return max_elem(v, left, left_end);
  } else if (rnk < left_size) {
    return get_elem_by_rnk(v, left, left_end, rnk);
  } else {
    return get_elem_by_rnk(v, left_end + 1, right, rnk - left_size);
  }
}

ll get_elem_by_rnk(vector<ll> &v, ll rnk) {
  return get_elem_by_rnk(v, 0, v.size() - 1, rnk);
}

vector<ll> smallest_k(vector<ll> v, ll k) {
  if (k <= 0 || k > v.size())
    throw invalid_argument{"k must be in (0, v.size())"};
  ll threshold = get_elem_by_rnk(v, k - 1);
  vector<ll> smallest(k);
  ll cnt = 0;
  for (auto _v : v) {
    if (_v <= threshold) {
      smallest[cnt] = _v;
      ++cnt;
    }
  }
  return smallest;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  ll n, k;
  ifs >> n >> k;
  vector<ll> v(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> v[i];
  }
  vector<ll> res = smallest_k(v, k);
  for (ll i = 0; i < res.size(); ++i) {
    printf("%lld%c", res[i], i == res.size() - 1 ? '\n' : ' ');
  }
  puts("");
}

int main() {
  solve("../testcases/17_14/v04_01.txt");
  solve("../testcases/17_14/v04_02.txt");
}
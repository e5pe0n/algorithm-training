// Cracking the Coding Interview p.570
// O(n), array having duplicate elements is allowed
#include <algorithm>
#include <fstream>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

default_random_engine generator;

struct PartitionResult {
  ll left_size = 0;
  ll mid_size = 0;
};

PartitionResult partition(vector<ll> &v, ll start, ll end, ll pivot) {
  ll left = start;
  ll right = end;
  ll mid = start;
  while (mid <= right) {
    if (v[mid] < pivot) {
      swap(v[mid], v[left]);
      ++mid, ++left;
    } else if (v[mid] > pivot) {
      swap(v[mid], v[right]);
      --right;
    } else
      ++mid;
  }
  return PartitionResult{left - start, right - left + 1};
}

ll rnd_int_in_rng(ll mi, ll ma) {
  uniform_int_distribution<ll> dist{mi, ma};
  return dist(generator);
}

ll get_elem_by_rnk(vector<ll> &v, ll k, ll start, ll end) {
  ll pivot = v[rnd_int_in_rng(start, end)];
  PartitionResult p = partition(v, start, end, pivot);
  ll left_size = p.left_size;
  ll mid_size = p.mid_size;
  if (k < left_size) {
    return get_elem_by_rnk(v, k, start, start + left_size - 1);
  } else if (k < left_size + mid_size) {
    return pivot;
  } else {
    return get_elem_by_rnk(
        v, k - left_size - mid_size, start + left_size + mid_size, end);
  }
}

ll get_elem_by_rnk(vector<ll> &v, ll k) {
  if (k >= v.size()) throw invalid_argument{"k must be less than v.size()"};
  return get_elem_by_rnk(v, k, 0, v.size() - 1);
}

vector<ll> smallest_k(vector<ll> &v, ll k) {
  if (k <= 0 || k > v.size())
    throw invalid_argument{"k must be in (0, v.size())"};
  ll threshold = get_elem_by_rnk(v, k - 1);
  vector<ll> smallest(k);
  ll cnt = 0;
  for (auto _v : v) {
    if (_v < threshold) { smallest[cnt++] = _v; }
  }
  while (cnt < k) {
    smallest[cnt++] = threshold;
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
  sort(res.begin(), res.end());
  for (ll i = 0; i < res.size(); ++i) {
    printf("%lld%c", res[i], i == res.size() - 1 ? '\n' : ' ');
  }
  puts("");
}

int main() {
  solve("../testcases/17_14/01.txt");
  solve("../testcases/17_14/02.txt");
  solve("../testcases/17_14/03.txt");
  solve("../testcases/17_14/04.txt");
}

// # ../testcases/17_14/01.txt
// -5 -2 -1

// # ../testcases/17_14/02.txt
// -9 -7 -7 -3 -2 0 1 3 5 6

// # ../testcases/17_14/03.txt
// -6 -6 -5 -5 -4 -4 -2 -1 -1 -1 0 0 2 3 3 4 4 4 8 8 9 11 12 12 13 13 16 16 17
// 17 18 21 22 23 23 24 24 24 24 25 26 28 28 29 30 31 32 33 35 40 41 41 42 43 48
// 49 49 50 51 51 55 55 57 58 59 59 59 61 62 62 63 64 65 65 66 67 67 68 68 70 71
// 71 72 75 75 75 77 77 77 78 78 79 79 80 80 80 81 83 87 89

// # ../testcases/17_14/04.txt
// 0 0 0
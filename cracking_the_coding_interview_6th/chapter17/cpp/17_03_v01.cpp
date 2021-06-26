#include <algorithm>
#include <chrono>
#include <fstream>
#include <random>
#include <set>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using hrc = chrono::high_resolution_clock;

void _gen_rand_set(vector<ll> &src,
                   const ll m,
                   ll i,
                   default_random_engine &generator) {
  if (i < m) return;
  _gen_rand_set(src, m, i - 1, generator);
  uniform_int_distribution<ll> distribution(0, i);
  ll x = distribution(generator);
  swap(src[x], src[i]);
}

vector<ll> gen_rand_set(vector<ll> &v, const ll m) {
  set<ll> s(v.begin(), v.end());
  vector<ll> _v(s.begin(), s.end());
  auto seed = hrc::now().time_since_epoch().count();
  default_random_engine generator(seed);
  _gen_rand_set(_v, m, _v.size() - 1, generator);
  vector<ll> res(_v.begin(), _v.begin() + min((ll)v.size(), m));
  return res;
}

void print_v(const vector<ll> v) {
  for (ll i = 0; i < v.size(); ++i) {
    printf("%lld%c", v[i], i == v.size() - 1 ? '\n' : ' ');
  }
}

int main() {
  vector<ll> v{-9, -8, -7, -7, -6, -5, -5, -4, -3, -2, -2, -1, 0, 0, 0,
               1,  2,  3,  3,  4,  5,  5,  6,  6,  6,  7,  8,  8, 9, 9};
  for (ll i = 0; i < 5; ++i) {
    vector<ll> res = gen_rand_set(v, 5);
    print_v(res);
  }
}
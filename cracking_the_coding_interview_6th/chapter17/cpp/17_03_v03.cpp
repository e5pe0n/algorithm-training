#include <chrono>
#include <random>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using hrc = chrono::high_resolution_clock;

vector<ll> pick_m_iteratively(vector<ll> org, ll m) {
  if (org.size() < m) return org;
  vector<ll> subset(org.begin(), org.begin() + m);
  auto seed = hrc::now().time_since_epoch().count();
  default_random_engine generator{seed};
  for (ll i = m; i < org.size(); ++i) {
    uniform_int_distribution<ll> distribution{0, i};
    ll x = distribution(generator);
    if (x < m) subset[x] = org[i];
  }
  return subset;
}

void print_v(const vector<ll> &v) {
  for (ll i = 0; i < v.size(); ++i) {
    printf("%lld%c", v[i], i == v.size() - 1 ? '\n' : ' ');
  }
}

int main() {
  vector<ll> v{-9, -8, -7, -7, -6, -5, -5, -4, -3, -2, -2, -1, 0, 0, 0,
               1,  2,  3,  3,  4,  5,  5,  6,  6,  6,  7,  8,  8, 9, 9};
  for (ll i = 0; i < 5; ++i) {
    vector<ll> res = pick_m_iteratively(v, 5);
    print_v(res);
  }
}
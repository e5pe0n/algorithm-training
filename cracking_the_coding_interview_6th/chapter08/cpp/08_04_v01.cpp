#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

void show_subsets(const vector<vector<ll>> &subsets) {
  cout << "{\n";
  for (auto subset : subsets) {
    cout << " {";
    for (ll i = 0; i < subset.size(); ++i) {
      cout << subset[i] << (i == subset.size() - 1 ? "" : ", ");
    }
    cout << "}," << endl;
  }
  cout << "}\n" << endl;
}

void solve(const string &fp) {
  cout << "# " << fp << endl;
  ifstream ifs(fp);
  ll n;
  ifs >> n;
  vector<ll> v(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> v[i];
  }
  vector<vector<ll>> subsets;
  for (ll i = 0; i < (1 << n); ++i) {
    vector<ll> subset;
    for (ll j = 0; j < n; ++j) {
      if (i >> j & 1) { subset.push_back(v[j]); }
    }
    subsets.push_back(subset);
  }
  show_subsets(subsets);
}

int main() {
  solve("../testcases/08_04/01.txt");
}

// {
//  {},
//  {10},
//  {20},
//  {10, 20},
//  {30},
//  {10, 30},
//  {20, 30},
//  {10, 20, 30},
//  {40},
//  {10, 40},
//  {20, 40},
//  {10, 20, 40},
//  {30, 40},
//  {10, 30, 40},
//  {20, 30, 40},
//  {10, 20, 30, 40},
//  {50},
//  {10, 50},
//  {20, 50},
//  {10, 20, 50},
//  {30, 50},
//  {10, 30, 50},
//  {20, 30, 50},
//  {10, 20, 30, 50},
//  {40, 50},
//  {10, 40, 50},
//  {20, 40, 50},
//  {10, 20, 40, 50},
//  {30, 40, 50},
//  {10, 30, 40, 50},
//  {20, 30, 40, 50},
//  {10, 20, 30, 40, 50},
// }
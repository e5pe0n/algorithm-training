// this version cannot be applied to a array contains not distinct elements.
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

void solve(const string &fp) {
  cout << "# " << fp << endl;
  ifstream ifs(fp);
  ll n;
  ifs >> n;
  vector<ll> v(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> v[i];
  }
  ll left = 0, right = n;
  while (right - left > 1) {
    ll mid = (left + right) / 2;
    if (mid >= v[mid])
      left = mid;
    else
      right = mid;
  }
  if (left == v[left])
    cout << left << endl;
  else
    cout << "no exists" << endl;
  cout << endl;
}

int main() {
  solve("../testcases/08_03/01.txt");
  solve("../testcases/08_03/02.txt");
}

// # ../testcases/08_03/01.txt
// 7

// # ../testcases/08_03/02.txt
// no exists
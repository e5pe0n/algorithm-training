#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

ll search(const vector<ll> &v, const ll x) {
  ll left = 0;
  ll right = v.size() - 1;
  while (left < right) {
    ll mid = (left + right) / 2;
    if (v[left] == x) return left;
    if (v[mid] == x) return mid;
    if (v[right] == x) return right;
    if (v[left] > v[mid]) {
      if (v[mid] < x && x < v[right])
        left = mid + 1;
      else
        right = mid - 1;
    } else {
      if (v[left] < x && x < v[mid])
        right = mid - 1;
      else
        left = mid + 1;
    }
  }
  return left;
}

void solve(const string &fp) {
  cout << "# " << fp << endl;
  ifstream ifs(fp);
  ll n, x;
  ifs >> n >> x;
  vector<ll> v(n);
  for (ll i = 0; i < n; ++i)
    ifs >> v[i];
  cout << search(v, x) << "\n" << endl;
}

int main() {
  solve("../testcases/10_03/01.txt");
  solve("../testcases/10_03/02.txt");
  solve("../testcases/10_03/03.txt");
  solve("../testcases/10_03/04.txt");
  solve("../testcases/10_03/05.txt");
}

// # ../testcases/10_03/01.txt
// 8

// # ../testcases/10_03/02.txt
// 4

// # ../testcases/10_03/03.txt
// 1

// # ../testcases/10_03/04.txt
// 7

// # ../testcases/10_03/05.txt
// 8
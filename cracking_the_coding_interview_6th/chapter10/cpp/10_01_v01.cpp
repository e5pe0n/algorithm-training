#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

void merge_sort(vector<ll> &a, const ll na, vector<ll> &b, const ll nb) {
  ll idx = a.size() - 1;
  ll ia = na - 1;
  ll ib = nb - 1;
  while (ia >= 0 && ib >= 0) {
    if (a[ia] >= b[ib]) {
      a[idx--] = a[ia--];
    } else {
      a[idx--] = b[ib--];
    }
  }
  while (ia >= 0) {
    a[idx--] = a[ia--];
  }
  while (ib >= 0) {
    a[idx--] = b[ib--];
  }
}

void solve(const string &fp) {
  cout << "# " << fp << endl;
  ifstream ifs(fp);
  ll n, na, nb;
  ifs >> n >> na >> nb;
  vector<ll> a(n);
  vector<ll> b(nb);
  for (ll i = 0; i < na; ++i) {
    ifs >> a[i];
  }
  for (ll i = 0; i < nb; ++i) {
    ifs >> b[i];
  }
  merge_sort(a, na, b, nb);
  for (auto _a : a)
    cout << _a << " ";
  cout << "\n" << endl;
}

int main() {
  solve("../testcases/10_01/01.txt");
  solve("../testcases/10_01/02.txt");
}

// # ../testcases/10_01/01.txt
// 0 1 2 3 4 5 6 7 8 9

// # ../testcases/10_01/02.txt
// 0 1 2 3 4 5 6 7 8 9

#include <bitset>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
using ll = long long;

void solve(const string fp) {
  printf("%s\n", fp.c_str());
  ifstream ifs{fp};
  string N, M;
  ll fst, last;
  ifs >> N >> M >> fst >> last;
  bitset<32> bn(N);
  bitset<32> bm(M);
  ll idx = 0;
  for (ll i = fst; i <= last; ++i) {
    bn.set(i, bm[idx++]);
  }
  cout << bn << '\n' << endl;
}

int main() {
  solve("../testcases/05_01/01.txt");
  solve("../testcases/05_01/02.txt");
  solve("../testcases/05_01/03.txt");
  solve("../testcases/05_01/04.txt");
}
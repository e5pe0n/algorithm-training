#include <fstream>
#include <functional>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

string compress1(string s) {
  string t = s + '_';
  ll cnt = 0;
  string res;
  for (ll i = 0; i < t.size() - 1; ++i) {
    ++cnt;
    if (t[i] != t[i + 1]) {
      // res += t[i] + to_string(cnt);
      res += t[i];
      res += to_string(cnt);
      cnt = 0;
    }
  }
  return res.size() < s.size() ? res : s;
}

void show(const function<string(string)> &f,
          const string &fn,
          const vector<string> &ss) {
  printf("# %s\n", fn.c_str());
  for (auto s : ss) {
    printf("%s -> %s\n", s.c_str(), f(s).c_str());
  }
  puts("");
}

int main() {
  ifstream ifs("../testcases/1_06.txt");
  ll n;
  ifs >> n;
  vector<string> ss(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> ss[i];
  }
  show(compress1, "compress1", ss);
}
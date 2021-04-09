#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, string> pls;

string urlify1(string s, ll n) {
  s = s.substr(0, n);
  string res;
  for (auto c : s) {
    if (c == ' ')
      res += "%20";
    else
      res += c;
  }
  return res;
}

pls parse_input(string s) {
  string n_str;
  for (auto c : s) {
    if ('0' <= c && c <= '9') {
      n_str += c;
    } else {
      break;
    }
  }
  ll n = stoll(n_str);
  string t = s.substr(n_str.size() + 1);
  return {n, t};
}

void show(const function<string(string, ll)> &f,
          const string &fn,
          const vector<pls> &ps) {
  printf("# %s\n", fn.c_str());
  for (auto p : ps) {
    printf("%s\n", urlify1(p.second, p.first).c_str());
  }
  puts("");
}

int main() {
  ifstream ifs("../testcases/1_03.txt");
  string n_str;
  ll n;
  getline(ifs, n_str);
  n = stoll(n_str);
  vector<pls> ps;
  for (ll i = 0; i < n; ++i) {
    string line;
    getline(ifs, line);
    ps.push_back(parse_input(line));
  }
  show(urlify1, "urlify1", ps);
}
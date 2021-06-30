#include <fstream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

string find_longest_subarr(const string &s) {
  vector<ll> sum_alpha(s.size() + 1);
  vector<ll> sum_num(s.size() + 1);
  for (ll i = 0; i < s.size(); ++i) {
    sum_alpha[i + 1] = sum_alpha[i];
    sum_num[i + 1] = sum_num[i];
    if (isalpha(s[i]))
      ++sum_alpha[i + 1];
    else
      ++sum_num[i + 1];
  }
  ll left = 0, right = 0;
  for (ll i = 0; i < s.size(); ++i) {
    for (ll j = i + 1; j < s.size() + 1; ++j) {
      ll alphas = sum_alpha[j] - sum_alpha[i];
      ll nums = sum_num[j] - sum_num[i];
      if (alphas == nums && right - left < j - i) {
        left = i;
        right = j;
      }
    }
  }
  return s.substr(left, right - left);
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  string s;
  ifs >> s;
  string res = find_longest_subarr(s);
  puts(res.c_str());
  puts("");
}

int main() {
  solve("../testcases/17_05/01.txt");
  solve("../testcases/17_05/02.txt");
  solve("../testcases/17_05/03.txt");
  solve("../testcases/17_05/04.txt");
}
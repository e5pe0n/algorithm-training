#include <fstream>
#include <functional>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<string, string> pss;

const ll D = 256;
const ll Q = 1'000'000'007;

ll mod_pow(ll x, ll n, ll m) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % m;
    x = x * x % m;
    n >>= 1;
  }
  return res;
}

bool rabin_karp(const string &pat,
                const string &txt,
                const ll &d,
                const ll &q) {
  ll m = pat.size();
  ll n = txt.size();
  ll h = mod_pow(d, m - 1, q);
  ll p = 0, t = 0;
  for (ll i = 0; i < m; ++i) {
    p = (d * p + pat[i]) % q;
    t = (d * t + txt[i]) % q;
  }
  printf("%lld, %lld\n", p, t);
  for (ll i = 0; i <= n - m; ++i) {
    if (p == t && txt.substr(i, m) == pat) return true;
    if (i < n - m) {
      t = (d * (t - txt[i] * h) + txt[i + m]) % q;
      t = (t + q) % q;
    }
  }
  return false;
}

bool is_substr(const string &pat, const string &str) {
  return rabin_karp(pat, str, D, Q);
}

bool is_rotation(const string &s, const string &t) {
  return is_substr(s, t + t);
}

void show(const function<bool(string, string)> &f,
          const string &fn,
          const vector<pss> &vss) {
  printf("# %s\n", fn.c_str());
  for (auto p : vss) {
    auto [s, t] = p;
    printf("%s is %srotation of %s\n",
           s.c_str(),
           f(s, t) ? "" : "not ",
           t.c_str());
  }
  puts("");
}

int main() {
  ifstream ifs("../testcases/1_09.txt");
  ll n;
  ifs >> n;
  vector<pss> vss(n);
  for (ll i = 0; i < n; ++i) {
    string s, t;
    ifs >> s >> t;
    vss[i] = {s, t};
  }
  show(is_rotation, "is_rotation", vss);
}

// # is_rotation
// waterbottle is rotation of erbottlewat
// abbbbaabbba is rotation of aabbbaabbbb
// abbbaaabbba is not rotation of aabbbaabbbb
// abcdefghifkl is not rotation of abcdefabcdef
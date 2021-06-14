#include <fstream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

struct MatchRes {
  bool match = false;
  string sa, sb;
};

MatchRes pat_match(const string &val, string pat) {
  string org_pat{pat};
  ll na = 0, nb = 0;
  for (auto c : pat) {
    if (c == 'a')
      ++na;
    else
      ++nb;
  }
  if (na == 0) {
    swap(na, nb);
    pat = string(na, 'a');
  }
  if (nb == 0) {
    if (val.size() % na != 0) return MatchRes{false};
    ll la = val.size() / na;
    string sa = val.substr(0, la);
    ll idx = 0;
    for (auto c : pat) {
      string s{};
      for (ll i = 0; i < la; ++i) {
        s += val[idx++];
      }
      if (s != sa) return MatchRes{false};
    }
    return MatchRes{
        true, org_pat[0] == 'a' ? sa : "", org_pat[0] == 'b' ? sa : ""};
  }
  for (ll la = 1; la <= val.size() / na; ++la) {
    ll t = val.size() - la * na;
    if (t == 0 || t % nb != 0) continue;
    ll lb = t / nb;
    string sa{}, sb{};
    ll idx = 0;
    bool match = true;
    for (auto c : pat) {
      string s{};
      if (c == 'a') {
        for (ll i = 0; i < la; ++i) {
          s += val[idx++];
        }
        if (s == "") continue;
        if (sa == "")
          sa = s;
        else if (s != sa) {
          match = false;
          break;
        }
      } else {
        for (ll i = 0; i < lb; ++i) {
          s += val[idx++];
        }
        if (s == "") continue;
        if (sb == "")
          sb = s;
        else if (s != sb) {
          match = false;
          break;
        }
      }
    }
    if (match) { return MatchRes{true, sa, sb}; };
  }
  return MatchRes{false};
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  string val;
  ifs >> val;
  ll n;
  ifs >> n;
  vector<string> pats(n);
  for (ll i = 0; i < n; ++i) {
    ifs >> pats[i];
  }
  puts(val.c_str());
  for (auto pat : pats) {
    MatchRes res = pat_match(val, pat);
    printf("%s: %s", pat.c_str(), res.match ? "true" : "false");
    if (res.match) {
      printf(" / sa=%s, sb=%s", res.sa.c_str(), res.sb.c_str());
    }
    puts("");
  }
  puts("");
}

int main() {
  solve("../testcases/16_18/01.txt");
  solve("../testcases/16_18/02.txt");
  solve("../testcases/16_18/03.txt");
}

// # ../testcases/16_18/01.txt
// catcatgocatgo
// aabab: true / sa=cat, sb=go
// a: true / sa=catcatgocatgo, sb=
// ab: true / sa=c, sb=atcatgocatgo
// abb: true / sa=cat, sb=catgo
// b: true / sa=, sb=catcatgocatgo
// aab: true / sa=cat, sb=gocatgo

// # ../testcases/16_18/02.txt
// catcagocatgo
// aabab: false
// a: true / sa=catcagocatgo, sb=
// ab: true / sa=c, sb=atcagocatgo
// abb: false
// b: true / sa=, sb=catcagocatgo
// aab: false

// # ../testcases/16_18/03.txt
// catcatcatcatcat
// aabab: true / sa=cat, sb=cat
// a: true / sa=catcatcatcatcat, sb=
// ab: true / sa=c, sb=atcatcatcatcat
// abb: true / sa=cat, sb=catcat
// b: true / sa=, sb=catcatcatcatcat
// aab: true / sa=cat, sb=catcatcat

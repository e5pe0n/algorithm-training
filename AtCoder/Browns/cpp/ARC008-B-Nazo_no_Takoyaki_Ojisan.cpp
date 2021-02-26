#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M;
string name, kit;

int main() {
  cin >> N >> M >> name >> kit;
  map<char, ll> Cname;
  for (auto c : name)
    ++Cname[c];
  map<char, ll> Ckit;
  for (auto c : kit)
    ++Ckit[c];
  ll res = -1;
  for (auto p : Cname) {
    ll cnt_name = p.second;
    ll cnt_kit = Ckit[p.first];
    if (cnt_kit == 0) {
      res = -1;
      break;
    }
    res = max(res, (cnt_name + cnt_kit - 1) / cnt_kit);
  }
  printf("%lld\n", res);
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;

int main() {
  cin >> N;
  if (N == 1) {
    puts("0");
    return 0;
  }
  string NS = to_string(N);
  string fst = NS.substr(0, (NS.size() + 1) / 2);
  string scnd = NS.substr((NS.size() + 1) / 2);
  ll cnt = 0;
  for (ll i = 1; i <= stoll(fst); ++i) {
    if (stoll(to_string(i) + to_string(i)) <= N) ++cnt;
  }
  printf("%lld\n", cnt);
}
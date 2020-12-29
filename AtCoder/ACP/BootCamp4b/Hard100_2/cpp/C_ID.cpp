#include <bits/stdc++.h>
#define MAX_M 100'000
using namespace std;
typedef long long ll;
typedef pair<ll, string> pls;

ll N, M;
ll P[MAX_M], Y[MAX_M];

string i2s(ll x) {
  string res = to_string(x);
  int n = res.size();
  for (int i = 0; n + i < 6; ++i) {
    res = '0' + res;
  }
  return res;
}

void solve() {
  vector<vector<ll>> V;
  for (int i = 0; i < M; ++i) {
    V.push_back({Y[i], P[i], i});
  }
  sort(V.begin(), V.end());
  map<ll, ll> C;
  vector<pls> res;
  for (int i = 0; i < M; ++i) {
    ll y = V[i][0];
    ll p = V[i][1];
    ll idx = V[i][2];
    string n = i2s(p) + i2s(++C[p]);
    res.push_back({idx, n});
  }
  sort(res.begin(), res.end());
  for (int i = 0; i < M; ++i) {
    printf("%s\n", res[i].second.c_str());
  }
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    cin >> P[i] >> Y[i];
  }
  solve();
}
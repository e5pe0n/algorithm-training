#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = long long;
template <typename T, typename U> using umap = unordered_map<T, U>;

ll cnt_ways(ll n,
            const vector<ll> &coins,
            ll idx,
            umap<ll, umap<ll, ll>> cache) {
  if (cache[n][idx] != 0) return cache[n][idx];
  if (idx == coins.size() - 1) return 1;
  ll res = 0;
  for (ll sum = 0; sum <= n; sum += coins[idx]) {
    res += cnt_ways(n - sum, coins, idx + 1, cache);
  }
  cache[n][idx] = res;
  return res;
}

void solve(const ll n) {
  cout << "# " << n << " cents" << endl;
  vector<ll> coins{25, 10, 5, 1};
  umap<ll, umap<ll, ll>> cache;
  cout << cnt_ways(n, coins, 0, cache) << "\n" << endl;
}

int main() {
  solve(25);
  solve(52);
}

// # 25 cents
// 13

// # 52 cents
// 49

#include <bits/stdc++.h>
#define MAX_NA 100'000
#define MAX_NB 100'000
using namespace std;
typedef long long ll;

ll NA, NB;
set<ll> A;
set<ll> B;
set<ll> U;

int main() {
  cin >> NA >> NB;
  for (ll i = 0; i < NA; ++i) {
    ll a;
    cin >> a;
    A.insert(a);
    U.insert(a);
  }
  for (ll i = 0; i < NB; ++i) {
    ll b;
    cin >> b;
    B.insert(b);
    U.insert(b);
  }
  ll inter = 0;
  for (auto a : A) {
    if (B.count(a)) ++inter;
  }
  ll uni = U.size();
  printf("%.7f\n", (double)inter / uni);
}
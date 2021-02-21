#include <bits/stdc++.h>
#define MAX_N 777
using namespace std;
typedef long long ll;

ll B[10];
ll N;
ll A[MAX_N];

int main() {
  for (ll i = 0; i < 10; ++i) {
    ll b;
    cin >> b;
    B[b] = i;
  }
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  auto comp = [](ll &left, ll &right) {
    string s = to_string(left);
    string t = to_string(right);
    if (s.size() == t.size()) {
      for (ll i = 0; i < s.size(); ++i) {
        if (s[i] == t[i]) continue;
        return B[s[i] - '0'] < B[t[i] - '0'];
      }
      return true;
    }
    return s.size() < t.size();
  };
  sort(A, A + N, comp);
  for (ll i = 0; i < N; ++i) {
    printf("%lld\n", A[i]);
  }
}
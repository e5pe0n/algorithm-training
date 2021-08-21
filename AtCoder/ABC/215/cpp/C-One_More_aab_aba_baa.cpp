#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string S;
ll K;

int main() {
  cin >> S >> K;
  sort(S.begin(), S.end());
  vector<string> ss;
  do {
    ss.push_back(S);
  } while (next_permutation(S.begin(), S.end()));
  printf("%s\n", ss[K - 1].c_str());
}
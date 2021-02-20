#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;

map<char, char> M{
    {'b', 1 + '0'}, {'c', 1 + '0'}, {'d', 2 + '0'}, {'w', 2 + '0'},
    {'t', 3 + '0'}, {'j', 3 + '0'}, {'f', 4 + '0'}, {'q', 4 + '0'},
    {'l', 5 + '0'}, {'v', 5 + '0'}, {'s', 6 + '0'}, {'x', 6 + '0'},
    {'p', 7 + '0'}, {'m', 7 + '0'}, {'h', 8 + '0'}, {'k', 8 + '0'},
    {'n', 9 + '0'}, {'g', 9 + '0'}, {'z', 0 + '0'}, {'r', 0 + '0'}};

int main() {
  cin >> N;
  vector<string> res;
  for (ll i = 0; i < N; ++i) {
    string W;
    cin >> W;
    string r;
    for (auto c : W) {
      if (M.count(tolower(c))) r += M[tolower(c)];
    }
    if (r.size()) res.push_back(r);
  }
  if (res.size() == 0) {
    puts("");
    return 0;
  }
  for (ll i = 0; i < res.size(); ++i) {
    printf("%s%c", res[i].c_str(), i == res.size() - 1 ? '\n' : ' ');
  }
}
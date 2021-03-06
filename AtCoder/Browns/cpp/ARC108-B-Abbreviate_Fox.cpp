#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
string S;

int main() {
  cin >> N >> S;
  string T;
  for (auto c : S) {
    T += c;
    if (T.size() >= 3) {
      string last = T.substr(T.size() - 3);
      if (last == "fox") {
        T.pop_back();
        T.pop_back();
        T.pop_back();
      }
    }
  }
  printf("%ld\n", T.size());
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll Y, M, D;
ll days[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

string f() {
  stringstream ss;
  ss << setfill('0') << right << setw(4) << Y;
  ss << '/';
  ss << setfill('0') << right << setw(2) << M;
  ss << '/';
  ss << setfill('0') << right << setw(2) << D;
  return ss.str();
}

int main() {
  string S;
  cin >> S;
  Y = stoll(S.substr(0, 4));
  M = stoll(S.substr(5, 2));
  D = stoll(S.substr(8, 2));
  while (true) {
    ll *d = days[0];
    if (Y % 4 == 0 && Y % 100 != 0 || Y % 400 == 0) { d = days[1]; }
    while (M <= 12) {
      while (D <= d[M]) {
        if (Y % M == 0 && (Y / M) % D == 0) {
          puts(f().c_str());
          return 0;
        }
        ++D;
      }
      ++M;
      D = 1;
    }
    ++Y;
    M = 1;
    D = 1;
  }
}
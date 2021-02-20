#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll Deg, Dis;
string d[] = {"NNE",
              "NE",
              "ENE",
              "E",
              "ESE",
              "SE",
              "SSE",
              "S",
              "SSW",
              "SW",
              "WSW",
              "W",
              "WNW",
              "NW",
              "NNW"};

string f() {
  ll s = 1125;
  ll t = 2250;
  for (ll i = 0; i < 15; ++i) {
    if (s <= Deg && Deg < s + t) return d[i];
    s += t;
  }
  return "N";
}

ll g() {
  if (0 <= Dis && Dis <= 2) return 0;
  if (3 <= Dis && Dis <= 15) return 1;
  if (16 <= Dis && Dis <= 33) return 2;
  if (34 <= Dis && Dis <= 54) return 3;
  if (55 <= Dis && Dis <= 79) return 4;
  if (80 <= Dis && Dis <= 107) return 5;
  if (108 <= Dis && Dis <= 138) return 6;
  if (139 <= Dis && Dis <= 171) return 7;
  if (172 <= Dis && Dis <= 207) return 8;
  if (208 <= Dis && Dis <= 244) return 9;
  if (245 <= Dis && Dis <= 284) return 10;
  if (285 <= Dis && Dis <= 326) return 11;
  return 12;
}

int main() {
  cin >> Deg >> Dis;
  Deg *= 10;
  string W = f();
  Dis = (Dis * 100 / 60 + 5) / 10;
  ll S = g();
  if (S == 0) W = "C";
  printf("%s %lld\n", W.c_str(), S);
}
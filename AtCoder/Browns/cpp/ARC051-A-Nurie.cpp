#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const string Y = "YES", N = "NO";

ll X1, Y1, R;
ll X2, Y2, X3, Y3;

int main() {
  cin >> X1 >> Y1 >> R >> X2 >> Y2 >> X3 >> Y3;
  ll d1 = (X2 - X1) * (X2 - X1) + (Y2 - Y1) * (Y2 - Y1) - R * R;
  ll d2 = (X2 - X1) * (X2 - X1) + (Y3 - Y1) * (Y3 - Y1) - R * R;
  ll d3 = (X3 - X1) * (X3 - X1) + (Y2 - Y1) * (Y2 - Y1) - R * R;
  ll d4 = (X3 - X1) * (X3 - X1) + (Y3 - Y1) * (Y3 - Y1) - R * R;
  string red, blue;
  if (d1 <= 0 && d2 <= 0 && d3 <= 0 && d4 <= 0)
    red = Y, blue = N;
  else if (X2 <= X1 - R && X1 + R <= X3 && Y2 <= Y1 - R && Y1 + R <= Y3)
    red = N, blue = Y;
  else
    red = Y, blue = Y;
  puts(red.c_str());
  puts(blue.c_str());
}
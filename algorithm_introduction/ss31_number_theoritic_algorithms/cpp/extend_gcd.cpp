#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> extend_gcd(int a, int b) {
  if (b == 0) {
    vector<int> res{a, 1, 0};
    return res;
  }

  vector<int> res = extend_gcd(b, a % b);
  int x = res[2];
  int y = res[1] - (a / b) * res[2];
  res[1] = x;
  res[2] = y;
  return res;
}

string res_str(const vector<int> &res) {
  return "d=" + to_string(res[0]) + ", x=" + to_string(res[1]) + ", y=" + to_string(res[2]);
}

int main() {
  cout << "extend_gcd(12, 13): " << res_str(extend_gcd(12, 13)) << "\n";
  cout << "extend_gcd(12, 6): " << res_str(extend_gcd(12, 6)) << "\n";
  cout << "extend_gcd(12, 18): " << res_str(extend_gcd(12, 18)) << "\n";
  cout << "extend_gcd(14, 100): " << res_str(extend_gcd(14, 100)) << endl;
}
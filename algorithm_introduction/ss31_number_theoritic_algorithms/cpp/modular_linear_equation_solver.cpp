#include <iostream>
#include <string>
#include <vector>

using namespace std;

string vector_str(const vector<int> &vec) {
  string s = "[";
  for (auto i : vec) {
    s += to_string(i) + ", ";
  }
  return s + "]";
}

vector<int> extend_gcd(int a, int b) {
  if (b == 0)
    return vector<int>{a, 1, 0};
  vector<int> res = extend_gcd(b, a % b);
  int x = res[2];
  int y = res[1] - (a / b) * res[2];
  res[1] = x;
  res[2] = y;
  return res;
}

int add_bias(int x, int n) { return (x + n) % n; }

vector<int> modular_linear_equation_solver(int a, int b, int n) {
  vector<int> sol_res;
  vector<int> gcd_res = extend_gcd(a, n);
  int d = gcd_res[0];
  int _x = gcd_res[1];
  int _y = gcd_res[2];
  if (b % d == 0) {
    int x0 = (_x * (b / d)) % n;
    for (int i = 0; i < d; ++i) {
      sol_res.push_back(add_bias((x0 + i * (n / d)) % n, n));
    }
  }
  return sol_res;
}

int main() {
  vector<int> res = modular_linear_equation_solver(14, 30, 100);
  cout << vector_str(res) << endl; // [95, 45,]
}
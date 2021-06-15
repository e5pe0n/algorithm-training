#include <fstream>
#include <functional>
#include <string>
using namespace std;
using ll = long long;

double _eval(const string expr, ll head, ll last) {
  ll i = last;
  auto f = [&expr, &i, &head, &last](function<double(double, double)> op) {
    return op(_eval(expr, head, i - 1), _eval(expr, i + 1, last));
  };
  for (; i >= head; --i) {
    if (expr[i] == '+') return f(plus<double>());
    if (expr[i] == '-') return f(minus<double>());
  }
  i = last;
  for (; i >= head; --i) {
    if (expr[i] == '*') return f(multiplies<double>());
    if (expr[i] == '/') return f(divides<double>());
  }
  return stod(expr.substr(head, last - head + 1));
}

double eval(const string expr) {
  return _eval(expr, 0, expr.size() - 1);
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  string expr;
  ifs >> expr;
  printf("%f\n", eval(expr));
  puts("");
}

int main() {
  solve("../testcases/16_26/01.txt");
  solve("../testcases/16_26/02.txt");
  solve("../testcases/16_26/03.txt");
}

// # ../testcases/16_26/01.txt
// 23.500000

// # ../testcases/16_26/02.txt
// 120.000000

// # ../testcases/16_26/03.txt
// 99.000000

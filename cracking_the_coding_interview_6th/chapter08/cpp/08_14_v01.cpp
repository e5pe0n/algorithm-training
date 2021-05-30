#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

enum class Op { AND, OR, XOR };

pair<vector<Op>, vector<bool>> parse(string expr) {
  vector<Op> ops;
  vector<bool> operands;
  for (auto c : expr) {
    if (c == '&') ops.push_back(Op::AND);
    if (c == '|') ops.push_back(Op::OR);
    if (c == '^') ops.push_back(Op::XOR);
    if (c == '0') operands.push_back(0);
    if (c == '1') operands.push_back(1);
  }
  return {ops, operands};
}

ll cnt_eval(const string &expr, const bool res) {
  auto [ops, operands] = parse(expr);
  ll n = operands.size();
  ll m = ops.size();
  vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2)));
  for (ll i = 0; i < n; ++i) {
    if (operands[i] == 1)
      dp[i][i][1] = 1;
    else
      dp[i][i][0] = 1;
  }
  for (ll w = 1; w < n; ++w) {
    for (ll i = 0; i + w < n; ++i) {
      ll j = i + w;
      for (ll k = i; k < j; ++k) {
        if (ops[k] == Op::AND) {
          dp[i][j][0] += dp[i][k][0] * dp[k + 1][j][0];
          dp[i][j][0] += dp[i][k][0] * dp[k + 1][j][1];
          dp[i][j][0] += dp[i][k][1] * dp[k + 1][j][0];
          dp[i][j][1] += dp[i][k][1] * dp[k + 1][j][1];
        }
        if (ops[k] == Op::OR) {
          dp[i][j][0] += dp[i][k][0] * dp[k + 1][j][0];
          dp[i][j][1] += dp[i][k][0] * dp[k + 1][j][1];
          dp[i][j][1] += dp[i][k][1] * dp[k + 1][j][0];
          dp[i][j][1] += dp[i][k][1] * dp[k + 1][j][1];
        }
        if (ops[k] == Op::XOR) {
          dp[i][j][0] += dp[i][k][0] * dp[k + 1][j][0];
          dp[i][j][1] += dp[i][k][0] * dp[k + 1][j][1];
          dp[i][j][1] += dp[i][k][1] * dp[k + 1][j][0];
          dp[i][j][0] += dp[i][k][1] * dp[k + 1][j][1];
        }
      }
    }
  }
  return dp[0][n - 1][res];
}

void solve(const string &fp) {
  cout << "# " << fp << endl;
  ifstream ifs(fp);
  string expr;
  bool res;
  ifs >> expr >> res;
  cout << cnt_eval(expr, res) << "\n" << endl;
}

int main() {
  solve("../testcases/08_14/01.txt");
  solve("../testcases/08_14/02.txt");
}

// # ../testcases/08_14/01.txt
// 2

// # ../testcases/08_14/02.txt
// 10

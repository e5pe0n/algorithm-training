// Cracking the Coding Interview p.525
#include <fstream>
#include <regex>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

class Term {
public:
  enum class Operator { ADD, SUB, MUL, DIV, BLANK };
  double v;
  Operator op;
  Term(double _v, Operator _op) : v(_v), op(_op) {}
  static vector<Term> parse_term_seq(string);
  const static regex TERM_PAT;
  string repr() {
    string res;
    switch (op) {
    case Operator::ADD:
      res += "+";
      break;
    case Operator::SUB:
      res += "-";
      break;
    case Operator::MUL:
      res += "*";
      break;
    case Operator::DIV:
      res += "/";
      break;
    default:
      res += " ";
      break;
    }
    return res += to_string(v);
  }
};

vector<Term> Term::parse_term_seq(string seq) {
  vector<Term> res;
  regex pat{R"(([\+\-\*\/]?)([0-9]+))"};
  for (sregex_iterator p(seq.begin(), seq.end(), pat); p != sregex_iterator{};
       ++p) {
    if ((*p)[1] == '+')
      res.emplace_back(stod((*p)[2]), Operator::ADD);
    else if ((*p)[1] == '-')
      res.emplace_back(stod((*p)[2]), Operator::SUB);
    else if ((*p)[1] == '*')
      res.emplace_back(stod((*p)[2]), Operator::MUL);
    else if ((*p)[1] == '/')
      res.emplace_back(stod((*p)[2]), Operator::DIV);
    else
      res.emplace_back(stod((*p)[2]), Operator::BLANK);
  }
  return res;
}

double apply_op(double left, Term::Operator op, double right) {
  switch (op) {
  case Term::Operator::ADD:
    return left + right;
  case Term::Operator::SUB:
    return left - right;
  case Term::Operator::MUL:
    return left * right;
  case Term::Operator::DIV:
    return left / right;
  default:
    return right;
  }
}

Term *collapse_term(Term *primary, Term *secondary) {
  if (!primary) return secondary;
  if (!secondary) return primary;
  double v = apply_op(primary->v, secondary->op, secondary->v);
  primary->v = v;
  return primary;
}

double compute(string seq) {
  vector<Term> terms = Term::parse_term_seq(seq);
  double res = 0;
  Term *processing = nullptr;
  for (ll i = 0; i < terms.size(); ++i) {
    Term *curr = &terms[i];
    Term *nxt = i + 1 < terms.size() ? &terms[i + 1] : nullptr;
    processing = collapse_term(processing, curr);
    if (nxt == nullptr || nxt->op == Term::Operator::ADD
        || nxt->op == Term::Operator::SUB) {
      res = apply_op(res, processing->op, processing->v);
      processing = nullptr;
    }
  }
  return res;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  string expr;
  ifs >> expr;
  printf("%f\n", compute(expr));
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

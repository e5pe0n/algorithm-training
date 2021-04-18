// Cracking the Coding Interview p.233
#include <cstdio>
#include <exception>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

const ll INF = 1e9;

class EmptyStackException : public exception {
  virtual const char *what() const throw() {
    return "stack is empty";
  }
} ese;

class FullStackException : public exception {
  virtual const char *what() const throw() {
    return "stack is full";
  }
} fse;

class Stack {
protected:
  vector<ll> v;
  ll pt = 0;
  ll capacity;

public:
  Stack() {}
  Stack(ll _capacity) : capacity(_capacity) {
    v = vector<ll>(capacity);
  }

  ll size() {
    return pt;
  }

  virtual void push(ll x) {
    if (is_full()) throw fse;
    v[pt++] = x;
  }

  virtual ll pop() {
    if (is_empty()) throw ese;
    return v[--pt];
  }

  ll peek() {
    if (is_empty()) throw ese;
    return v[pt - 1];
  }

  bool is_full() {
    return pt == capacity;
  }

  bool is_empty() {
    return pt == 0;
  }

  string to_str() {
    string res = "  [";
    stringstream ss;
    for (auto _v : v) {
      ss << setw(2) << to_string(_v);
      ss << ' ';
    }
    res += ss.str();
    res.pop_back();
    res += "]\n";
    res += "pt ";
    for (ll i = 0; i < v.size(); ++i) {
      if (i == pt)
        res += " ^ ";
      else
        res += "   ";
    }
    res.pop_back();
    return res;
  }
};

class MinStack : public Stack {
private:
  Stack mins;

public:
  MinStack(ll _capacity) : Stack(_capacity) {
    mins = Stack(_capacity);
  }

  void push(ll x) override {
    if (x <= min()) mins.push(x);
    Stack::push(x);
  }

  ll pop() override {
    ll x = Stack::pop();
    if (x == min()) mins.pop();
    return x;
  }

  ll min() {
    return mins.is_empty() ? INF : mins.peek();
  }
};

int main() {
  MinStack ms(10);
  ms.push(5);
  ms.push(3);
  ms.push(7);
  printf("%s\n", ms.to_str().c_str());
  printf("%lld\n", ms.min());
  puts("");

  ms.pop();
  ms.pop();
  printf("%s\n", ms.to_str().c_str());
  printf("%lld\n", ms.min());
  puts("");

  ms.push(7);
  ms.push(3);
  ms.push(9);
  ms.push(1);
  printf("%s\n", ms.to_str().c_str());
  printf("%lld\n", ms.min());
  puts("");

  for (ll i = 0; i < 4; ++i) {
    ms.pop();
    printf("%s\n", ms.to_str().c_str());
    printf("%lld\n", ms.min());
    puts("");
  }
  printf("%s\n", ms.to_str().c_str());
  printf("%lld\n", ms.min());
}

//   [ 5  3  7  0  0  0  0  0  0  0]
// pt           ^
// 3

//   [ 5  3  7  0  0  0  0  0  0  0]
// pt     ^
// 5

//   [ 5  7  3  9  1  0  0  0  0  0]
// pt                 ^
// 1

//   [ 5  7  3  9  1  0  0  0  0  0]
// pt              ^
// 3

//   [ 5  7  3  9  1  0  0  0  0  0]
// pt           ^
// 3

//   [ 5  7  3  9  1  0  0  0  0  0]
// pt        ^
// 5

//   [ 5  7  3  9  1  0  0  0  0  0]
// pt     ^
// 5

//   [ 5  7  3  9  1  0  0  0  0  0]
// pt     ^
// 5

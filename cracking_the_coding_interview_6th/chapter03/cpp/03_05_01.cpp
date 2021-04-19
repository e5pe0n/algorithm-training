// Cracking the Coding Interview p.238
#include <cstdio>
#include <exception>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

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
};

void sort_stack(Stack &s) {
  Stack work = Stack(s.size());
  while (!s.is_empty()) {
    ll x = s.pop();
    while (!work.is_empty() && x < work.peek()) {
      s.push(work.pop());
    }
    work.push(x);
  }
  while (!work.is_empty()) {
    s.push(work.pop());
  }
}

int main() {
  Stack s(10);
  s.push(30);
  s.push(80);
  s.push(20);
  s.push(40);
  s.push(10);
  s.push(70);
  s.push(60);
  s.push(50);
  sort_stack(s);
  while (!s.is_empty()) {
    printf("%lld\n", s.pop());
  }
}

// 10
// 20
// 30
// 40
// 50
// 60
// 70
// 80
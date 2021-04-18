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

class EmptyQueueException : public exception {
  virtual const char *what() const throw() {
    return "queue is empty";
  }
} eqe;

class FullQueueException : public exception {
  virtual const char *what() const throw() {
    return "queue is full";
  }
} fqe;

class Stack {
protected:
  ll pt = 0;
  ll capacity;

public:
  vector<ll> v;
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

class MyQueue {
private:
  ll capacity;
  Stack input, output;

public:
  MyQueue(ll _capacity) : capacity(_capacity) {
    input = Stack(capacity);
    output = Stack(capacity);
  }

  string to_str() {
    vector<ll> *v_out = &output.v;
    vector<ll> *v_in = &input.v;
    string res = "[";
    stringstream ss;
    for (ll i = v_out->size() - 1; i >= 0; --i) {
      ss << setw(2) << v_out->at(i) << " ";
    }
    for (ll i = 0; i < v_in->size(); ++i) {
      ss << setw(2) << v_in->at(i) << " ";
    }
    res += ss.str();
    res.pop_back();
    return res += "]";
  }

  ll size() {
    return input.size() + output.size();
  }

  void enqueue(ll x) {
    if (is_full()) throw fqe;
    input.push(x);
  }

  ll dequeue() {
    if (is_empty()) throw eqe;
    if (output.is_empty()) migrate();
    return output.pop();
  }

  ll peek() {
    if (is_empty()) throw eqe;
    if (output.is_empty()) migrate();
    return output.peek();
  }

  void migrate() {
    while (!input.is_empty()) {
      output.push(input.pop());
    }
  }

  bool is_empty() {
    return size() == 0;
  }

  bool is_full() {
    return size() == capacity;
  }
};

int main() {
  MyQueue mq(10);
  for (ll i = 10; i < 20; ++i) {
    mq.enqueue(i);
  }
  printf("%s\n", mq.to_str().c_str());
  for (ll i = 0; i < 10; ++i) {
    printf("%lld\n", mq.dequeue());
  }
  for (ll i = 50; i < 54; ++i) {
    mq.enqueue(i);
  }
  printf("%s\n", mq.to_str().c_str());
  for (ll i = 0; i < 2; ++i) {
    printf("%lld\n", mq.dequeue());
  }
  printf("%s\n", mq.to_str().c_str());
}

// [ 0  0  0  0  0  0  0  0  0  0 10 11 12 13 14 15 16 17 18 19]
// 10
// 11
// 12
// 13
// 14
// 15
// 16
// 17
// 18
// 19
// [10 11 12 13 14 15 16 17 18 19 50 51 52 53 14 15 16 17 18 19]
// 50
// 51
// [10 11 12 13 14 15 50 51 52 53 50 51 52 53 14 15 16 17 18 19]

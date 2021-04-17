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

struct ThreeInOne {
  struct Stack {
    ll pt;
    ll btm;
    ll size;
    Stack() {}
    Stack(ll _btm, ll _size) : btm(_btm), size(_size) {
      pt = btm;
    }
  };

  vector<ll> v;
  Stack *s1;
  Stack *s2;
  Stack *s3;
  ll each_size;
  ThreeInOne(ll _each_size) : each_size(_each_size) {
    v = vector<ll>(each_size * 3);
    s1 = new Stack(0, each_size);
    s2 = new Stack(each_size, each_size);
    s3 = new Stack(each_size * 2, each_size);
  }
  ~ThreeInOne() {
    delete s1, s2, s3;
  }
  string to_str() {
    string res = "   [";
    stringstream ss;
    for (auto _v : v) {
      ss << setw(2) << to_string(_v);
      ss << ' ';
    }
    res += ss.str();
    res.pop_back();
    res += "]\n";
    res += "btm ";
    for (ll i = 0; i < v.size(); ++i) {
      if (i == s1->btm || i == s2->btm || i == s3->btm) {
        res += " ^ ";
      } else
        res += "   ";
    }
    res.pop_back();
    res += "\n";
    res += "pt  ";
    for (ll i = 0; i < v.size(); ++i) {
      if (i == s1->pt || i == s2->pt || i == s3->pt) {
        res += " ^ ";
      } else
        res += "   ";
    }
    res.pop_back();
    return res += "\n";
  }

  ll pop(Stack *s) {
    if (is_empty(s)) throw ese;
    return v[--s->pt];
  }

  void push(Stack *s, ll x) {
    if (is_full(s)) throw fse;
    v[s->pt++] = x;
  }

  ll peek(Stack *s) {
    if (is_empty(s)) throw ese;
    return v[s->pt - 1];
  }

  bool is_empty(Stack *s) {
    return s->pt <= s->btm;
  }

  bool is_full(Stack *s) {
    return s->pt - s->btm >= s->size;
  }
};

int main() {
  ThreeInOne tio(5);
  for (ll i = 10; i < 13; ++i) {
    tio.push(tio.s1, i), tio.push(tio.s2, i), tio.push(tio.s3, i);
  }
  printf("%s\n", tio.to_str().c_str());
  printf("%lld\n", tio.pop(tio.s1));
  printf("%lld\n", tio.pop(tio.s1));
  printf("%s\n", tio.to_str().c_str());
  printf("%lld\n", tio.pop(tio.s2));
  printf("%lld\n", tio.pop(tio.s3));
  printf("%lld\n", tio.pop(tio.s3));
  printf("%s\n", tio.to_str().c_str());
  printf("%lld\n", tio.peek(tio.s1));
  printf("%lld\n", tio.peek(tio.s2));
  printf("%lld\n", tio.peek(tio.s3));

  tio.push(tio.s1, 20);
  tio.push(tio.s2, 20);
  tio.push(tio.s3, 20);
  printf("%s\n", tio.to_str().c_str());
}

//    [10 11 12  0  0 10 11 12  0  0 10 11 12  0  0]
// btm  ^              ^              ^
// pt            ^              ^              ^

// 12
// 11
//    [10 11 12  0  0 10 11 12  0  0 10 11 12  0  0]
// btm  ^              ^              ^
// pt      ^                    ^              ^

// 12
// 12
// 11
//    [10 11 12  0  0 10 11 12  0  0 10 11 12  0  0]
// btm  ^              ^              ^
// pt      ^                 ^           ^

// 10
// 11
// 10
//    [10 20 12  0  0 10 11 20  0  0 10 20 12  0  0]
// btm  ^              ^              ^
// pt         ^                 ^           ^

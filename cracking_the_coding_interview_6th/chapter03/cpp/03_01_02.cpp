#include <cassert>
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
    Stack(ll _pt, ll _size) : pt(_pt), size(_size) {
      btm = pt;
    }
  };

  vector<ll> v;
  ll size;
  Stack *s1;
  Stack *s2;
  Stack *s3;
  ThreeInOne(ll each_size) {
    v = vector<ll>(each_size * 3);
    size = v.size();
    s1 = new Stack(0, each_size);
    s2 = new Stack(each_size, each_size);
    s3 = new Stack(each_size * 2, each_size);
  }
  ~ThreeInOne() {
    delete s1, s2, s3;
  }

  ll _pt(Stack *s) {
    return s->pt < s->btm ? s->pt + size : s->pt;
  }

  ll pop(Stack *s) {
    if (is_empty(s)) throw ese;
    s->pt = ((s->pt - 1) % size + size) % size;
    return v[s->pt];
  }

  void push(Stack *s, ll x) {
    if (is_full(s)) modify(s);
    v[s->pt] = x;
    s->pt = (s->pt + 1) % size;
  }

  ll peek(Stack *s) {
    if (is_empty(s)) throw ese;
    return v[s->pt - 1];
  }

  bool is_empty(Stack *s) {
    return s->pt == s->btm;
  }

  bool is_full(Stack *s) {
    return _pt(s) - s->btm >= s->size;
  }

  bool are_all_full() {
    return (_pt(s1) - s1->btm) + (_pt(s2) - s2->btm) + (_pt(s3) - s3->btm)
           >= size;
  }

  void _shift(Stack *s) {
    for (ll i = _pt(s); i > s->btm; --i) {
      v[i % size] = v[((i - 1) % size + size) % size];
    }
    s->btm = (s->btm + 1) % size;
    s->pt = (s->pt + 1) % size;
  }

  void _shrink(Stack *s) {
    _shift(s);
    --s->size;
  }

  void _modify(Stack *target, Stack *next, Stack *next_next) {
    if (!is_full(next)) {
      _shrink(next);
    } else {
      _shrink(next_next);
      _shift(next);
    }
    ++target->size;
  }

  void modify(Stack *s) {
    if (are_all_full()) throw fse;
    if (s == s1) {
      _modify(s1, s2, s3);
    } else if (s == s2) {
      _modify(s2, s3, s1);
    } else if (s == s3) {
      _modify(s3, s1, s2);
    }
    printf("s1->size=%lld, 2->size=%lld, s3->size=%lld, size=%lld\n",
           s1->size,
           s2->size,
           s3->size,
           size);
    printf("s1: pt-btm=%lld, s2: pt-btm=%lld, s3: pt-btm=%lld, size=%lld\n",
           _pt(s1) - s1->btm,
           _pt(s2) - s2->btm,
           _pt(s3) - s3->btm,
           size);
    assert(s1->size + s2->size + s3->size == v.size()
           && (_pt(s1) - s1->btm) + (_pt(s2) - s2->btm) + (_pt(s3) - s3->btm)
                  <= v.size());
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
};

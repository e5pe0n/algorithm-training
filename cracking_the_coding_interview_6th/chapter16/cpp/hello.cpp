#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct A {
  virtual void dummy() = 0;
};

struct B : public A {
  string _name;
  void dummy() override {}
  B(string name) : _name(name) {}
};

struct C : public A {
  ll _value;
  void dummy() override {}
  C(ll value) : _value(value) {}
};

int main() {
  vector<shared_ptr<A>> v;
  v.push_back(make_shared<B>("B"));
  v.push_back(make_shared<C>(3));
  for (auto _v : v) {
    if (auto b = dynamic_cast<B *>(_v.get())) {
      cout << b->_name << endl;
    } else if (auto c = dynamic_cast<C *>(_v.get())) {
      cout << c->_value << endl;
    }
  }
}

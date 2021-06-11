#include <fstream>
#include <iostream>
#include <regex>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

namespace XMLParser {

struct Element;
struct Elem;
struct Attribute;
struct Body;

struct Attribute {
  string name;
  string value;
  string repr() {
    return name + "=\"" + value + "\"";
  }
  Attribute(string _name, string _value) : name(_name), value(_value) {}
};

struct Elem {
  virtual string repr() = 0;
};

struct Element : public Elem {
  string name;
  vector<Attribute> attributes;
  vector<shared_ptr<Elem>> children;
  Element(string _name, vector<Attribute> _attributes)
      : name(_name), attributes(_attributes) {}
  void close() {
    _closed = true;
  }
  bool closed() {
    return _closed;
  }
  string repr() override {
    string s{"<" + name};
    if (attributes.size()) {
      s += ' ';
      for (auto attr : attributes) {
        s += attr.repr();
      }
    }
    s += '>';
    if (children.size()) {
      for (auto child : children) {
        s += child->repr();
      }
    }
    return s += "</" + name + ">";
  }

private:
  bool _closed = false;
};

struct Body : public Elem {
  string text;
  string repr() override {
    return text;
  }
  Body(string _text) : text(_text) {}
};

const string TAG_PAT_R{R"(<.*?>)"};
const string BODY_PAT_R{R"(\s*[^\s<>][^<>]*[^\s<>]\s*)"};

const regex TAG_PAT{TAG_PAT_R};
const regex BODY_PAT{BODY_PAT_R};
const regex END_TAG_PAT{R"(/<.*?>)"};
const regex ELEM_PAT{TAG_PAT_R + "|" + BODY_PAT_R};

const regex TAG_GRP_PAT{R"(<(\w+)\s*?(.*?)>)"};
const regex END_TAG_GRP_PAT{R"(</(\w+)>)"};
const regex ATTR_GRP_PAT{R"(([\w-]+)=\"(.*?)\")"};

vector<Attribute> attr_parser(const string &s) {
  vector<Attribute> attrs;
  sregex_iterator end{};
  for (sregex_iterator p{s.begin(), s.end(), ATTR_GRP_PAT}; p != end; ++p) {
    attrs.emplace_back((*p)[1], (*p)[2]);
  }
  return attrs;
}

Element parser(const string &s) {
  stack<shared_ptr<Elem>> stk;
  sregex_iterator end{};
  for (sregex_iterator p{s.begin(), s.end(), ELEM_PAT}; p != end; ++p) {
    smatch m{};
    string _s = (*p)[0].str();
    if (regex_search(_s, m, END_TAG_GRP_PAT)) {
      vector<shared_ptr<Elem>> children;
      while (stk.size()) {
        if (auto elem = dynamic_cast<Element *>(stk.top().get())) {
          if (elem->name == m[1].str() && !elem->closed()) break;
        }
        children.push_back(stk.top());
        stk.pop();
      }
      reverse(children.begin(), children.end());
      if (auto elem = dynamic_cast<Element *>(stk.top().get())) {
        elem->children = children;
        elem->close();
      }
    } else if (regex_search(_s, m, TAG_GRP_PAT)) {
      stk.push(make_shared<Element>(m[1].str(), attr_parser(m[2].str())));
    } else {
      stk.push(make_shared<Body>((*p)[0].str()));
    }
  }
  if (auto elem = dynamic_cast<Element *>(stk.top().get())) {
    return *elem;
  } else {
    throw "parse failed";
  }
}

}; // namespace XMLParser

int main() {
  using namespace XMLParser;
  ifstream ifs("../testcases/16_11/03.xml");
  string s;
  for (string line; getline(ifs, line);) {
    s += line;
  }
  cout << s << '\n' << endl;
  Element e = parser(s);
  cout << e.repr() << endl;
}
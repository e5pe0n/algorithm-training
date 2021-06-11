#include "xml_parser.cpp"
#include <algorithm>
#include <fstream>
#include <map>
#include <memory>
#include <string>
#include <vector>
using namespace std;
using namespace XMLParser;
using ll = long long;

const string END = "0";

void _encode(Elem *elem, map<string, string> &code_map, vector<string> &res) {
  if (auto e = dynamic_cast<Element *>(elem)) {
    res.push_back(code_map[e->name]);
    for (auto attr : e->attributes) {
      res.push_back(code_map[attr.name]);
      res.push_back(attr.value);
    }
    res.push_back(END);
    for (auto child : e->children) {
      _encode(child.get(), code_map, res);
    }
    res.push_back(END);
  } else if (auto b = dynamic_cast<Body *>(elem)) {
    res.push_back(b->text);
  }
}

vector<string> encode(Element &e, map<string, string> &code_map) {
  vector<string> res;
  _encode(&e, code_map, res);
  return res;
}

void solve(const string &xml_path, const string &txt_path) {
  printf("# %s / %s\n", xml_path.c_str(), txt_path.c_str());
  ifstream ifs_xml{xml_path};
  string xml;
  for (string line; getline(ifs_xml, line);) {
    xml += line;
  }
  ifstream ifs_txt(txt_path);
  map<string, string> code_map;
  ll n;
  ifs_txt >> n;
  for (ll i = 0; i < n; ++i) {
    string tag, code;
    ifs_txt >> tag >> code;
    code_map[tag] = code;
  }
  Element e = parser(xml);
  vector<string> res = encode(e, code_map);
  for (ll i = 0; i < res.size(); ++i) {
    printf("%s%c", res[i].c_str(), i == res.size() - 1 ? '\n' : ' ');
  }
  puts("");
}

int main() {
  solve("../testcases/16_11/01.xml", "../testcases/16_11/01.txt");
  solve("../testcases/16_11/02.xml", "../testcases/16_11/02.txt");
  solve("../testcases/16_11/03.xml", "../testcases/16_11/03.txt");
}

// # ../testcases/16_11/01.xml / ../testcases/16_11/01.txt
// 1 4 McDowell 5 CA 0 2 3 Gayle 0 Some Message 0 0

// # ../testcases/16_11/02.xml / ../testcases/16_11/02.txt
// 1 6 card 7 width: 18rem; 0 2 8 ... 6 card-img-top 9 ... 0 0 1 6 card-body 0 3
// 6 card-title 0 Card title 0 4 6 card-text 0 Some quick example text to build
// on the card title and make up the bulk of the card's content. 0 5 10 # 6 btn
// btn-primary 0 Go somewhere 0 0 0

// # ../testcases/16_11/03.xml / ../testcases/16_11/03.txt
// 9 0 1 10 outer 11 v1-2 0 1 12 inner 0 Inner elem1 0 0 2 0 Elem2 0 3 13 v3-1
// 14 v3-2 15 v3-3 0 4 0 5 0 Choose one!! 0 6 16 op1 0 7 17 op1 0 Option 1 0 7
// 17 op2 0 Option 2 0 7 17 op3 0 Option 3 0 7 17 op4 0 Option 4 0 0 0 8 18
// margin: 5px; 0 Click me!! 0 0 0

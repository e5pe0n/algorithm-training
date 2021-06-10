#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const regex PAT{R"(\w=\w)"};

int main() {
  string s{"2=5"};
  smatch m;
  if (regex_search(s, m, PAT)) { cout << m[0] << endl; }
}
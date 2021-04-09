#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

string validate(string s) {
  string res;
  for (auto c : s) {
    if ('A' <= c && c <= 'z') { res += tolower(c); }
  }
  return res;
}

bool is_palindrome1(string s) {
  s = validate(s);
  ll b = 0;
  for (auto c : s) {
    b ^= 1 << (c - 'a');
  }
  ll odd = 0;
  for (auto c : s) {
    if (b & (1 << (c - 'a'))) ++odd;
  }
  return odd <= 1;
}

bool is_palindrome2(string s) {
  s = validate(s);
  ll b = 0;
  for (auto c : s) {
    b ^= 1 << (c - 'a');
  }
  return b & (b - 1) == 0;
  // e.g. b = 00010000, b - 1 = 00001111, b & (b - 1) = 0
  //      b = 00100111, b - 1 = 00101000, b & (b - 1) != 0
}

void show(const function<bool(string)> &f,
          const string &fn,
          const vector<string> &ss) {
  printf("# %s\n", fn.c_str());
  for (auto s : ss) {
    printf("%s is %spalindrome\n", s.c_str(), is_palindrome1(s) ? "" : "not ");
  }
  puts("");
}

int main() {
  ifstream ifs("../testcases/1_04.txt");
  string n_str;
  getline(ifs, n_str);
  ll n = stoll(n_str);
  vector<string> ss;
  for (ll i = 0; i < n; ++i) {
    string s;
    getline(ifs, s);
    ss.push_back(s);
  }
  show(is_palindrome1, "is_palindrome1", ss);
  show(is_palindrome2, "is_palindrome2", ss);
}
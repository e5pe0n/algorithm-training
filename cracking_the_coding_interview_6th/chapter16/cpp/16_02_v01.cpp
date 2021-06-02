#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

class WordCounter {
  string _book_name;
  map<string, ll> _cnt;

  void cnt_words(const string &text) {
    string word;
    for (auto c : text) {
      if (isalnum(c))
        word += tolower(c);
      else if (word.size()) {
        ++_cnt[word];
        word = "";
      }
    }
  }

public:
  WordCounter(const string &book_name, vector<string> &text)
      : _book_name(book_name) {
    for (const auto &s : text) {
      cnt_words(s);
    }
  }
  WordCounter(const string &book_name, string &text) : _book_name(book_name) {
    cnt_words(text);
  }

  string book_name() {
    return _book_name;
  }
  ll operator[](const string &key) {
    return _cnt[key];
  }
};

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  vector<string> text;
  for (string s; getline(ifs, s);) {
    text.push_back(s);
  }
  WordCounter wc{"Wikipedia Article about Machine Learning", text};
  printf("[%s] %lld\n", "machine", wc["machine"]);
  printf("[%s] %lld\n", "the", wc["the"]);
  printf("[%s] %lld\n", "it", wc["it"]);
  printf("[%s] %lld\n", "put", wc["put"]);
  puts("");
}

int main() {
  solve("../testcases/16_02/01.txt");
}

// # ../testcases/16_02/01.txt
// [machine] 7
// [the] 5
// [it] 2
// [put] 0
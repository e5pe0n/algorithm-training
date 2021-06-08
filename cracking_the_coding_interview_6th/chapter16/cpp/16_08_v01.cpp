#include <fstream>
#include <map>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

vector<string> units{"", "Thousand", "Million", "Billion"};
map<string, string> dict{
    {"0", "Zero"},      {"1", "One"},       {"2", "Two"},
    {"3", "Three"},     {"4", "Four"},      {"5", "Five"},
    {"6", "Six"},       {"7", "Seven"},     {"8", "Eight"},
    {"9", "Nine"},      {"10", "Ten"},      {"11", "Eleven"},
    {"12", "Twelve"},   {"13", "Thirteen"}, {"14", "Fourteen"},
    {"15", "Fifteen"},  {"16", "Sixteen"},  {"17", "Seventeen"},
    {"18", "Eighteen"}, {"19", "Nineteen"}, {"20", "Twenty"},
    {"30", "Thirty"},   {"40", "Fourty"},   {"50", "Fifty"},
    {"60", "Sixty"},    {"70", "Seventy"},  {"80", "Eighty"},
    {"90", "Ninety"},   {"100", "Hundred"}};

string read(string s) {
  bool all_zero = true;
  for (auto c : s) {
    if (c != '0') all_zero = false;
  }
  if (all_zero) return dict["0"];
  ll n = (s.size() + 3 - 1) / 3;
  s = string(3 * n - s.size(), '0') + s;
  string res;
  ll idx = 0;
  for (ll i = n - 1; i >= 0; --i) {
    ll left = idx;
    ll mid = left + 1;
    ll right = mid + 1;
    if (s[left] != '0') {
      res += dict[string(1, s[left])] + " " + dict["100"] + " ";
    }
    if (s[mid] != '0') {
      if (s[mid] == '1') {
        res += dict[s.substr(mid, 2)] + " ";
      } else {
        res += dict[string(1, s[mid]) + string(1, '0')] + " ";
      }
    }
    if (s[right] != '0' && s[mid] != '1') {
      res += dict[string(1, s[right])] + " ";
    }
    if (s[left] != '0' || s[mid] != '0' || s[right] != '0') {
      res += units[i] + ", ";
    }
    idx = right + 1;
  }
  res.pop_back();
  res.pop_back();
  return res;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  string s;
  ifs >> s;
  printf("%s: %s\n\n", s.c_str(), read(s).c_str());
}

int main() {
  solve("../testcases/16_08/01.txt");
  solve("../testcases/16_08/02.txt");
  solve("../testcases/16_08/03.txt");
  solve("../testcases/16_08/04.txt");
  solve("../testcases/16_08/05.txt");
  solve("../testcases/16_08/06.txt");
  solve("../testcases/16_08/07.txt");
}

// # ../testcases/16_08/01.txt
// 1234: One Thousand, Two Hundred Thirty Four

// # ../testcases/16_08/02.txt
// 54311: Fifty Four Thousand, Three Hundred Eleven

// # ../testcases/16_08/03.txt
// 123456789: One Hundred Twenty Three Million, Four Hundred Fifty Six Thousand,
// Seven Hundred Eighty Nine

// # ../testcases/16_08/04.txt
// 123456789012: One Hundred Twenty Three Billion, Four Hundred Fifty Six
// Million, Seven Hundred Eighty Nine Thousand, Twelve

// # ../testcases/16_08/05.txt
// 41203002001: Fourty One Billion, Two Hundred Three Million, Two Thousand, One

// # ../testcases/16_08/06.txt
// 5000000000: Five Billion

// # ../testcases/16_08/07.txt
// 0000000: Zero

#include <bitset>
#include <limits>
#include <string>
using namespace std;
using ll = long long;

ll b2d(string s) {
  ll t = stoi(s.substr(1, 31), nullptr, 2);
  ll ma = numeric_limits<int>::max();
  printf("ma=%lld, t=%lld\n", ma, t);
  return s[0] == '1' ? -((ma + 1) - t) : t;
}

int main() {
  string s1 = "01111111111111111111111111111111";
  string s2 = "11111111111111111111111111111111";
  printf("%lld\n", b2d(s1));
  printf("%lld\n", b2d(s2));

  bitset<32> b(-1);
  puts(b.to_string().c_str());
}
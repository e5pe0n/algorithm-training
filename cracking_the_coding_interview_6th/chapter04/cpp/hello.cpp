#include <list>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  vector<list<ll>> v;
  v.push_back(list<ll>{});
  printf("%ld\n", v.size());
  for (auto lst : v) {
    printf("%ld\n", lst.size());
  }
}
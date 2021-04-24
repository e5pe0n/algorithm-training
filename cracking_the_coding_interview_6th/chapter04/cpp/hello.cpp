#include <string>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  vector<ll> v(2);
  v.insert(v.begin() + 1, 100);
  for (auto _v : v)
    printf("%lld\n", _v);
}
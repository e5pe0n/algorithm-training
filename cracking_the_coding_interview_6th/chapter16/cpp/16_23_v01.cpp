#include <random>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

ll rand5() {
  default_random_engine generator;
  uniform_int_distribution<ll> distribution(0, 4);
  return distribution(generator);
}

ll rand7() {
  while (true) {
    ll sum = rand5() * 5 + rand5();
  }
}

int main() {}
#include <iostream>
#include <random>

using namespace std;

int main() {
  default_random_engine generator;
  uniform_int_distribution<int> distribution(1, 2);
  for (int i = 0; i < 5; ++i) {
    cout << distribution(generator) << ", ";
  }
  cout << endl;
}

#include <iostream>
#include <limits>

using namespace std;

int main() {
  cout << numeric_limits<double>::min() << endl;    //   2.22507e-308
  cout << numeric_limits<double>::lowest() << endl; // -1.79769e+308
}
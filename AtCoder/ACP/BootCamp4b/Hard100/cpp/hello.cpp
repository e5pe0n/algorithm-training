#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<int> V{0, 1, 10, 100};
  string n_str = "000";
  for (auto v : V) {
    string i_str = to_string(v);
    for (int i = 0; i < i_str.size(); ++i) {
      i_str = n_str[i]
    }
  }
}
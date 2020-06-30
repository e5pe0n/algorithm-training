#include <iostream>
#include <stdio.h>
#include <string>
#include <tuple>

using namespace std;

int main() {
  tuple<int, string, float> T[3] = {{1, "c", 1.5}, {2, "b", 2.3}, {3, "b", 0.5}};

  auto comp = [](const tuple<int, string, float> &t1, const tuple<int, string, float> &t2) {
    if (get<1>(t1) == get<1>(t2)) {
      return get<2>(t1) > get<2>(t2);
    } else {
      return get<1>(t1) < get<1>(t2);
    }
  };

  sort(T, T + 3, comp);
  for (auto &t : T) {
    printf("(%d, %s, %.1f)\n", get<0>(t), get<1>(t).c_str(), get<2>(t));
  }
}
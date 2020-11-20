#include <iostream>
#include <stdio.h>
#include <string>
#include <tuple>

#define MAX_N 100

using namespace std;

tuple<int, string, int> P[MAX_N];

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    string s;
    int p;
    cin >> s >> p;
    P[i] = {i + 1, s, p};
  }

  auto comp = [](const tuple<int, string, int> &p1, const tuple<int, string, int> &p2) {
    if (get<1>(p1) == get<1>(p2)) {
      return get<2>(p1) > get<2>(p2);
    } else {
      return get<1>(p1) < get<1>(p2);
    }
  };

  sort(P, P + N, comp);
  for (int i = 0; i < N; ++i) {
    printf("%d\n", get<0>(P[i]));
  }
}
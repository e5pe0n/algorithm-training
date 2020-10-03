#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <vector>

#define MAX_N 100'000
#define MAX_M 100'000

using namespace std;

int C[MAX_N]{};
string ID[MAX_M]{};

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> V;
  for (int i = 0; i < M; ++i) {
    int P, Y;
    cin >> P >> Y;
    V.push_back(vector<int>{Y, P, i});
  }
  sort(V.begin(), V.end());
  for (int i = 0; i < M; ++i) {
    int x = ++C[V[i][1] - 1];
    stringstream ss;
    ss << setfill('0') << setw(6) << V[i][2];
    ss << setfill('0') << setw(6) << V[i][1];
    ss << setfill('0') << setw(6) << x;
    ID[i] = ss.str();
  }
  sort(ID, ID + M);
  for (int i = 0; i < M; ++i) {
    printf("%s\n", ID[i].substr(6, ID[i].size() - 6).c_str());
  }
}
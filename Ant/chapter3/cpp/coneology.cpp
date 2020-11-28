#include <algorithm>
#include <fstream>
#include <set>
#include <stdio.h>
#include <utility>
#include <vector>

#define MAX_N 40000

using namespace std;
typedef pair<double, int> pdi;

int N;
double x[MAX_N], y[MAX_N], r[MAX_N];

// circle i is in circle j ?
bool inside(int i, int j) {
  double dx = x[i] - x[j];
  double dy = y[i] - y[j];
  return dx * dx + dy * dy <= r[j] * r[j];
}

void solve() {
  vector<pdi> events;
  for (int i = 0; i < N; ++i) {
    events.push_back({x[i] - r[i], i});
    events.push_back({x[i] + r[i], i + N});
  }
  sort(events.begin(), events.end());

  set<pdi> outers;
  vector<int> res;
  for (int i = 0; i < events.size(); ++i) {
    int id = events[i].second % N;
    if (events[i].second < N) { // left bound
      auto it = outers.lower_bound({y[id], id});
      if (it != outers.end() && inside(id, it->second)) {
        continue;
      }
      if (it != outers.begin() && inside(id, (--it)->second)) {
        continue;
      }
      res.push_back(id);
      outers.insert({y[id], id});
    } else { // right bound
      outers.erase({y[id], id});
    }
  }
  sort(res.begin(), res.end());
  printf("%d\n", res.size());
  for (int i = 0; i < res.size(); ++i) {
    printf("%d%c", res[i] + 1, i == res.size() - 1 ? '\n' : ' ');
  }
}

int main() {
  ifstream ifs("../testset/coneology/test2.txt");
  ifs >> N;
  for (int i = 0; i < N; ++i) {
    ifs >> x[i] >> y[i] >> r[i];
  }
  solve();
}
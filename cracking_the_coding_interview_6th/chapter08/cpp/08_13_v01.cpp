#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

struct Box {
  ll w, h, d;
};

ll stack_boxes(ll idx, const ll height, const ll last_idx, vector<Box> &boxes) {
  if (idx == boxes.size()) return height;
  ll res = stack_boxes(idx + 1, height, last_idx, boxes);
  if (last_idx == -1) {
    res = max(res, stack_boxes(idx + 1, height + boxes[idx].h, idx, boxes));
    return res;
  }
  Box &curr = boxes[idx];
  Box &last = boxes[last_idx];
  if (curr.w < last.w && curr.h < last.h && curr.d < last.d) {
    res = max(res, stack_boxes(idx + 1, height + curr.h, idx, boxes));
  }
  return res;
}

void solve(const string &fp) {
  cout << "# " << fp << endl;
  ifstream ifs(fp);
  ll n;
  ifs >> n;
  vector<Box> boxes(n);
  for (ll i = 0; i < n; ++i) {
    ll w, h, d;
    ifs >> w >> h >> d;
    boxes[i] = Box{w, h, d};
  }
  sort(boxes.begin(), boxes.end(), [](const Box &b1, const Box &b2) {
    return b1.w > b2.w;
  });
  cout << stack_boxes(0, 0, -1, boxes) << '\n' << endl;
}

int main() {
  solve("../testcases/08_13/01.txt");
  solve("../testcases/08_13/02.txt");
}

// # ../testcases/08_13/01.txt
// 12

// # ../testcases/08_13/02.txt
// 28

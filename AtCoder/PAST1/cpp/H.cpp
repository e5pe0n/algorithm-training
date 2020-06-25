#include <map>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

struct Input {
  int N;
  vector<int> C;
  int Q;
  vector<string> S;
};

void solve(int N, vector<int> C, int Q, vector<string> S) {
  int cnt = 0;
  for (auto s : S) {
    int head = 0;
    vector<int> v;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ' ') {
        v.push_back(stoi(s.substr(head, i - head)));
        head = i + 1;
      }
    }
    v.push_back(stoi(s.substr(head, s.size() - head)));

    if (v[0] == 1) {
      if (C[v[1] - 1] - v[2] >= 0) {
        C[v[1] - 1] -= v[2];
        cnt += v[2];
      }
    } else if (v[0] == 2) {
      bool flg = true;
      for (int i = 0; i < N; i += 2) {
        if (C[i] - v[1] < 0) {
          flg = false;
          break;
        }
      }
      if (flg) {
        for (int i = 0; i < N; i += 2) {
          C[i] -= v[1];
          cnt += v[1];
        }
      }
    } else {
      bool flg = true;
      for (int i = 0; i < N; ++i) {
        if (C[i] - v[1] < 0) {
          flg = false;
          break;
        }
      }
      if (flg) {
        for (int i = 0; i < N; ++i) {
          C[i] -= v[1];
          cnt += v[1];
        }
      }
    }
  }

  printf("%d\n", cnt);
}

int main() {
  map<string, Input> cases{
      {"case1",
       Input{4, vector<int>{5, 3, 3, 5}, 6, vector<string>{"1 2 1", "2 2", "2 2", "3 100", "3 1", "1 1 3"}}},
      {"case2", Input{10, vector<int>{241, 310, 105, 738, 405, 490, 158, 92, 68, 20}, 20,
                      vector<string>{"2 252", "1 4 36",  "2 69",  "1 5 406", "3 252", "1 3 8", "1 10 10",
                                     "3 11",  "1 4 703", "3 1",   "2 350",   "3 10",  "2 62",  "2 3",
                                     "2 274", "1 2 1",   "3 126", "1 4 702", "3 6",   "2 174"}}},
      {"case3", Input{2, vector<int>{3, 4}, 3, vector<string>{"1 2 9", "2 4", "3 4"}}}};

  for (auto [k, v] : cases) {
    printf("[%s]\n", k.c_str());
    solve(v.N, v.C, v.Q, v.S);
    printf("\n");
  }
}
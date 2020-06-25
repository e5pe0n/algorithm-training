#include <string>
#include <vector>

using namespace std;

void solve(vector<int> &v0, vector<string> &v1) {
  int N = v0[0];
  int Q = v0[1];

  vector<vector<char>> F(N, vector(N, 'N'));
  vector<vector<char>> _F(N, vector(N, 'N'));
  for (auto s : v1) {
    vector<int> v;
    int head = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ' ') {
        v.push_back(stoi(s.substr(head, i)));
        head = i + 1;
      }
    }
    v.push_back(stoi(s.substr(head, s.size() - head)));

    if (v[0] == 1) {
      _F[v[1] - 1][v[2] - 1] = 'Y';
    } else if (v[0] == 2) {
      for (int i = 0; i < N; ++i) {
        if (F[i][v[1] - 1] == 'Y') {
          _F[v[1] - 1][i] = 'Y';
        }
      }
    } else {
      for (int j = 0; j < N; ++j) {
        if (F[v[1] - 1][j] == 'Y') {
          for (int k = 0; k < N; ++k) {
            if (F[j][k] == 'Y') {
              _F[v[1] - 1][k] = 'Y';
            }
          }
        }
      }
    }
    F = _F;
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      printf("%c", F[i][j]);
    }
    printf("\n");
  }
}

int main() {
  vector<int> v0{6, 7};
  vector<string> v1{"1 1 2", "1 2 3", "1 3 4", "1 1 5", "1 5 6", "3 1", "2 6"};

  solve(v0, v1);
}
#include <bits/stdc++.h>
using namespace std;

string S;
int Q, T, F;
char C;

int main() {
  cin >> S >> Q;
  bool f = false;
  string front, back;
  vector<bool> v;
  for (int i = 0; i < Q; ++i) {
    cin >> T;
    v.push_back(f);
    if (T == 1) {
      f = !f;
    } else {
      cin >> F >> C;
      if (F == 1) {
        if (f) {
          back.push_back(C);
        } else {
          front.push_back(C);
        }
      } else {
        if (f) {
          front.push_back(C);
        } else {
          back.push_back(C);
        }
      }
    }
  }
  string res;
  if (f) {
    reverse(back.begin(), back.end());
    reverse(S.begin(), S.end());
    res = back + S + front;
  } else {
    reverse(front.begin(), front.end());
    res = front + S + back;
  }
  puts(res.c_str());
}
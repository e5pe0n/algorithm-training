#include <bits/stdc++.h>
using namespace std;

string S;
int Q;

int main() {
  cin >> S >> Q;
  bool f = true;
  string front;
  string back;
  for (int i = 0; i < Q; ++i) {
    int T;
    cin >> T;
    if (T == 1) {
      f = !f;
    } else {
      int F;
      char C;
      cin >> F >> C;
      if ((F == 1 && f) || (F == 2 && !f)) {
        front.push_back(C);
      } else {
        back.push_back(C);
      }
    }
  }
  string res;
  if (f) {
    reverse(front.begin(), front.end());
    res = front + S + back;
  } else {
    reverse(back.begin(), back.end());
    reverse(S.begin(), S.end());
    res = back + S + front;
  }
  printf("%s\n", res.c_str());
}
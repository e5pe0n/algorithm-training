#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
  cin >> N;
  set<string> st;
  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    st.insert(s);
  }
  printf("%ld\n", st.size());
}
#include <algorithm>
#include <ctype.h>
#include <map>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

void solve(string S) {
  vector<int> idxs;
  for (int i = 0; i < S.size(); ++i) {
    if (isupper(S[i])) {
      idxs.push_back(i);
    }
  }

  vector<string> ws;
  for (int i = 0; i < idxs.size(); i += 2) {
    string w = S.substr(idxs[i], idxs[i + 1] - idxs[i] + 1);
    w[0] = tolower(w[0]);
    w[w.size() - 1] = tolower(w[w.size() - 1]);
    ws.push_back(w);
  }

  sort(ws.begin(), ws.end());
  string res = "";
  for (auto w : ws) {
    w[0] = toupper(w[0]);
    w[w.size() - 1] = toupper(w[w.size() - 1]);
    res += w;
  }

  printf("%s\n", res.c_str());
}

int main() {
  map<string, string> cases{{"case1", "FisHDoGCaTAAAaAAbCAC"}, {"case2", "AAAAAjhfgaBCsahdfakGZsZGdEAA"}};

  for (auto &[k, v] : cases) {
    printf("[%s]\n", k.c_str());
    solve(v);
    printf("\n");
  }
}

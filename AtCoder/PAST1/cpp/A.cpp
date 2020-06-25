#include <map>
#include <regex>
#include <string>

using namespace std;

regex rx(R"(^[0-9]{3}$)");

void solve(string S) {
  if (regex_match(S, rx)) {
    printf("%d\n", stoi(S) * 2);
  } else {
    printf("error\n");
  }
}

int main() {
  map<string, string> cases{{"case1", "678"}, {"case2", "abc"}, {"case3", "0x8"}};

  for (auto &[k, v] : cases) {
    printf("[%s]\n", k.c_str());
    solve(v);
    printf("\n");
  }
}
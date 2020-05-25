#include <set>
#include <utility>

using namespace std;

int main() {
  set<pair<int, int>> E{make_pair<int, int>(3, 0), make_pair<int, int>(1, 3), make_pair<int, int>(1, 2)};

  auto search = E.find(make_pair<int, int>(3, 0));
  if (search != E.end()) {
    printf("(%d, %d)\n", search->first, search->second);
  } else {
    printf("Not found\n");
  }

  auto search2 = E.find(make_pair<int, int>(0, 3));
  if (search2 != E.end()) {
    printf("(%d, %d)\n", search2->first, search2->second);
  } else {
    printf("Not found\n");
  }
}
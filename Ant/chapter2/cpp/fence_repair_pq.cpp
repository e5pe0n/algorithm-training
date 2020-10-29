#include <fstream>
#include <queue>
#include <stdio.h>

#define MAX_N 20'000

using namespace std;

typedef long long ll;

int N;

int main() {
  ifstream ifs("../testset/fence_repair/test2.txt");
  ifs >> N;
  priority_queue<int, vector<int>, greater<int>> q;
  for (int i = 0; i < N; ++i) {
    int L;
    ifs >> L;
    q.push(L);
  }
  ll ans = 0;
  while (q.size() > 1) {
    ll mi1 = q.top();
    q.pop();
    ll mi2 = q.top();
    q.pop();
    ans += mi1 + mi2;
    q.push(mi1 + mi2);
  }
  printf("%lld\n", ans);
}
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>

#define MAX_N 20

using namespace std;

int N, K;
int A[MAX_N]{};
string ans;

bool dfs(int i, int s) {
  if (i == N) {
    return s == K;
  }
  return dfs(i + 1, s + A[i]) || dfs(i + 1, s);
}

int main() {
  ifstream ifs("../testset/partial_sum/test2.txt");
  ifs >> N;
  for (int i = 0; i < N; ++i) {
    ifs >> A[i];
  }
  ifs >> K;
  if (dfs(0, 0)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}
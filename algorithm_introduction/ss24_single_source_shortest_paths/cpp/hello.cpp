#include <limits>
#include <stdio.h>

using namespace std;

#define N 100
#define M 1'000

const int I_MAX = numeric_limits<int>::max();

int main() { printf("N: %d, M: %d, I_MAX: %d\n", N, M, I_MAX); }
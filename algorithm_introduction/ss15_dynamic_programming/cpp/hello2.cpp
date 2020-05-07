#include <stdio.h>

using namespace std;

int d_num = 0;

int root[][6]{{0, 0, 0, 0, 0, 0}, {0, 1, 1, 2, 2, 2}, {0, 0, 2, 2, 2, 4},
              {0, 0, 0, 3, 4, 5}, {0, 0, 0, 0, 4, 5}, {0, 0, 0, 0, 0, 5}};

void construct_optimal_bst(int root[][6], int i, int j, int p, int i_init, int j_init) {
  if (root[i][j] <= 0) {
    if (j < p) {
      printf("d%d is left child of k%d\n", d_num, p);
    } else {
      printf("d%d is right child of k%d\n", d_num, p);
    }
    ++d_num;
    return;
  }
  int r = root[i][j];
  if (i == i_init && j == j_init) {
    printf("k%d is root\n", r);
  } else if (j < p) {
    printf("k%d is left child of k%d\n", r, p);
  } else {
    printf("k%d is right child of k%d\n", r, p);
  }
  construct_optimal_bst(root, i, r - 1, r, i_init, j_init);
  construct_optimal_bst(root, r + 1, j, r, i_init, j_init);
}

int main() { construct_optimal_bst(root, 1, 5, 0, 1, 5); }
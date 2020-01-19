#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>

using namespace std;

struct Arr {
  int *arr;
  int size;

  string arr_str() {
    string s = "[";
    for (int i = 0; i < size; ++i) {
      s += to_string(arr[i]);
      s += ", ";
    }
    s += "]";
    return s;
  }
};

struct Case {
  Arr *org;
  Arr *res;
  int k;
};

void counting_sort(Arr *A, Arr *B, int k) {
  int *C = new int[k + 1]{};
  for (int i = 0; i < A->size; ++i) {
    C[A->arr[i]] += 1;
  }
  for (int i = 0; i < k; ++i) {
    C[i + 1] += C[i];
  }
  for (int i = A->size - 1; i >= 0; --i) {
    B->arr[C[A->arr[i]] - 1] = A->arr[i];
    C[A->arr[i]] -= 1;
  }

  delete[] C;
}

int main() {
  int X[] = {2, 5, 3, 0, 2, 3, 0, 3};
  int Y[] = {2, 5, 3, 0, 2, 3, 0, 3, 2};

  int size_X = sizeof(X) / sizeof(X[0]);
  int size_Y = sizeof(Y) / sizeof(Y[0]);

  int *res_X = new int[size_X]{};
  int *res_Y = new int[size_Y]{};

  Arr arr_X{X, size_X};
  Arr arr_res_X{res_X, size_X};

  Arr arr_Y{Y, size_Y};
  Arr arr_res_Y{res_Y, size_Y};

  unordered_map<string, Case> cases{{"A", Case{&arr_X, &arr_res_X, 5}},
                                    {"B", Case{&arr_Y, &arr_res_Y, 5}}};

  for (auto &p : cases) {
    cout << "# " << p.first << "\n";
    cout << "org: " << p.second.org->arr_str() << "\n";
    counting_sort(p.second.org, p.second.res, p.second.k);
    cout << "res: " << p.second.res->arr_str() << "\n";
  }

  delete[] res_X;
  delete[] res_Y;
}
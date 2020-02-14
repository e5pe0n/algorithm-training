#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int A[16];
int array_size = 16;

int object_size = 3;
int key_offset = 0;
int nxt_offset = 1;
int prv_offset = 2;
int head = -1;

int max_idx = array_size - array_size % object_size - 1;

string array_str() {
  stringstream idxs_ss;
  stringstream keys_ss;
  stringstream nxts_ss;
  stringstream prvs_ss;

  idxs_ss << "idxs: [";
  keys_ss << "keys: [";
  nxts_ss << "nxts: [";
  prvs_ss << "prvs: [";

  for (int i = 0; i <= max_idx; i += object_size) {
    idxs_ss << setw(2) << to_string(i) << ", ";
    keys_ss << setw(2) << to_string(A[i]) << ", ";
    nxts_ss << setw(2) << to_string(A[i + nxt_offset]) << ", ";
    prvs_ss << setw(2) << to_string(A[i + prv_offset]) << ", ";
  }

  idxs_ss << "]";
  keys_ss << "]";
  nxts_ss << "]";
  prvs_ss << "]";

  return idxs_ss.str() + "\n" + keys_ss.str() + "\n" + nxts_ss.str() + "\n" + prvs_ss.str();
}

void array_initialize() {
  for (int i = 0; i <= max_idx; i += object_size) {
    A[i] = -1;
    A[i + nxt_offset] = -1;
    A[i + prv_offset] = -1;
  }
}

int array_search(int key) {
  for (int i = 0; i <= max_idx; i += object_size) {
    if (A[i] == key) {
      return i;
    }
  }
  return -1;
}

int find_free_pos() { return array_search(-1); }

void array_insert(int key) {
  int pos = find_free_pos();
  if (pos < 0)
    throw "Overflow";

  A[pos] = key;
  A[pos + nxt_offset] = head;
  A[pos + prv_offset] = -1;

  if (head >= 0)
    A[head + prv_offset] = pos;
  head = pos;
}

void array_delete(int key) {
  int pos = array_search(key);
  if (pos >= 0) {
    if (A[pos + prv_offset] >= 0) {
      A[A[pos + prv_offset] + nxt_offset] = A[pos + nxt_offset];
    } else {
      head = A[pos + nxt_offset];
    }
    if (A[pos + nxt_offset] >= 0) {
      A[A[pos + nxt_offset] + prv_offset] = A[pos + prv_offset];
    }
    A[pos] = -1;
  }
}

int main() {
  array_initialize();

  array_insert(10);
  array_insert(11);
  array_insert(12);
  array_insert(13);
  array_insert(14);
  cout << array_str() << "\n";

  try {
    array_insert(15);
  } catch (const char *e) {
    cout << e << "\n";
  }

  cout << "array_search(10): " << to_string(array_search(10)) << "\n";
  cout << "array_search(12): " << to_string(array_search(12)) << "\n";
  cout << "array_search(14): " << to_string(array_search(14)) << "\n";
  cout << "array_search(15): " << to_string(array_search(15)) << "\n";

  cout << "\n";

  cout << "array_delete(10)\n";
  array_delete(10);
  cout << array_str() << "\n\n";
  cout << "array_delete(12)\n";
  array_delete(12);
  cout << array_str() << "\n\n";
  cout << "array_delete(14)\n";
  array_delete(14);
  cout << array_str() << "\n\n";

  cout << "array_search(10): " << to_string(array_search(10)) << "\n";
  cout << "array_search(12): " << to_string(array_search(12)) << "\n";
  cout << "array_search(14): " << to_string(array_search(14)) << "\n";
  array_insert(15);
  cout << array_str() << "\n" << endl;
}
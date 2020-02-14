#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int keys[5];
int prvs[5];
int nxts[5];

int array_size = 5;
int head = -1;

void array_initialize() {
  for (int i = 0; i < array_size; ++i) {
    keys[i] = -1;
    prvs[i] = -1;
    nxts[i] = -1;
  }
}

string array_str() {
  stringstream idxs_ss;
  stringstream prvs_ss;
  stringstream keys_ss;
  stringstream nxts_ss;

  idxs_ss << "idxs: [";
  prvs_ss << "prvs: [";
  keys_ss << "keys: [";
  nxts_ss << "nxts: [";

  for (int i = 0; i < array_size; ++i) {
    idxs_ss << setw(2) << to_string(i) << ", ";
    prvs_ss << setw(2) << to_string(prvs[i]) << ", ";
    keys_ss << setw(2) << to_string(keys[i]) << ", ";
    nxts_ss << setw(2) << to_string(nxts[i]) << ", ";
  }

  idxs_ss << "]";
  prvs_ss << "]";
  keys_ss << "]";
  nxts_ss << "]";
  return idxs_ss.str() + "\n" + prvs_ss.str() + "\n" + keys_ss.str() + "\n" + nxts_ss.str();
}

int array_search(int key) {
  for (int i = 0; i < array_size; ++i) {
    if (keys[i] == key)
      return i;
  }
  return -1;
}

int find_free_pos() { return array_search(-1); }

void array_insert(int key) {
  int pos = find_free_pos();
  if (pos < 0) {
    throw "Overflow";
  }

  keys[pos] = key;
  prvs[pos] = -1;
  nxts[pos] = head;

  if (head >= 0) {
    prvs[head] = pos;
  }
  head = pos;
}

void array_delete(int key) {
  int pos = array_search(key);
  if (pos >= 0) {
    if (prvs[pos] >= 0) {
      nxts[prvs[pos]] = nxts[pos];
    } else {
      head = nxts[pos];
    }
    if (nxts[pos] >= 0) {
      prvs[nxts[pos]] = prvs[pos];
    }
    keys[pos] = -1;
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
    cout << e << endl;
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
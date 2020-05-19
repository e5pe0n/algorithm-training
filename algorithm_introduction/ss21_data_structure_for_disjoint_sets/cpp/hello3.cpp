#include <stdio.h>
#include <string>

using namespace std;

struct El {
  El *p;
  int id;
  El() {}
  El(int id) : id(id), p(this) {}
  void update_p() { p = this; }
  string to_str() { return "el(id: " + to_string(id) + ", p: " + to_string(p->id) + ")"; }
};

El els[3];
El *Els[3];
El *K[6];

int main() {
  for (int i = 0; i < 3; ++i) {
    els[i] = El(i);
    els[i].update_p();
  }
  printf("%s\n", els[0].to_str().c_str());
  printf("\n");

  els[0] = El(0);
  els[1] = El(1);
  printf("%s\n", els[0].to_str().c_str());
  printf("%s\n", els[1].to_str().c_str());

  for (int i = 0; i < 3; ++i) {
    Els[i] = new El(i);
  }
  printf("%s\n", Els[0]->to_str().c_str());
  printf("%s\n", Els[1]->to_str().c_str());
  for (int i = 0; i < 3; ++i) {
    delete Els[i];
  }
}
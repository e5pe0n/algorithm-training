#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string greed = "Hello";
  string name = "World";

  greed += " ";
  for (int i = 0; i < name.size(); ++i) {
    greed += name[i];
  }

  printf("%s\n", greed.c_str());
}
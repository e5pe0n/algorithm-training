#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string Sa, Sb, Sc;
  cin >> Sa >> Sb >> Sc;
  int ia = 0;
  int ib = 0;
  int ic = 0;
  int Na = Sa.size();
  int Nb = Sb.size();
  int Nc = Sc.size();
  char t = 'a';
  while (true) {
    if (t == 'a') {
      while (ia < Na && Sa[ia] == 'a') {
        ++ia;
      }
      if (ia >= Na) {
        printf("A\n");
        return 0;
      }
      t = Sa[ia++];
    }
    if (t == 'b') {
      while (ib < Nb && Sb[ib] == 'b') {
        ++ib;
      }
      if (ib >= Nb) {
        printf("B\n");
        return 0;
      }
      t = Sb[ib++];
    }
    if (t == 'c') {
      while (ic < Nc && Sc[ic] == 'c') {
        ++ic;
      }
      if (ic >= Nc) {
        printf("C\n");
        return 0;
      }
      t = Sc[ic++];
    }
  }
}
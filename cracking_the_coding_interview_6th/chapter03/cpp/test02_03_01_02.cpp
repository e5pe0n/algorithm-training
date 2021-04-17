#include "03_01_02.cpp"

int main() {
  ThreeInOne tio(5);
  Stack *s1 = tio.s1, *s2 = tio.s2, *s3 = tio.s3;
  for (ll i = 10; i < 13; ++i) {
    tio.push(s1, i);
  }
  for (ll i = 20; i < 23; ++i) {
    tio.push(s2, i);
  }
  for (ll i = 30; i < 33; ++i) {
    tio.push(s3, i);
  }
  printf("%s\n", tio.to_str().c_str());
  for (ll i = 23; i < 29; ++i) {
    tio.push(s2, i);
  }
  printf("%s\n", tio.to_str().c_str());
  tio.push(s2, 29);
}

//    [10 11 12  0  0 20 21 22  0  0 30 31 32  0  0]
// btm  ^              ^              ^
// pt            ^              ^              ^

// s1->size=5, 2->size=6, s3->size=4, size=15
// s1: pt-btm=3, s2: pt-btm=5, s3: pt-btm=3, size=15
// s1->size=5, 2->size=7, s3->size=3, size=15
// s1: pt-btm=3, s2: pt-btm=6, s3: pt-btm=3, size=15
// s1->size=4, 2->size=8, s3->size=3, size=15
// s1: pt-btm=3, s2: pt-btm=7, s3: pt-btm=3, size=15
// s1->size=3, 2->size=9, s3->size=3, size=15
// s1: pt-btm=3, s2: pt-btm=8, s3: pt-btm=3, size=15
//    [31 32 10 11 12 20 21 22 23 24 25 26 27 28 30]
// btm        ^        ^                          ^
// pt         ^        ^                          ^

// terminate called after throwing an instance of 'FullStackException'
//   what():  stack is full
// Aborted
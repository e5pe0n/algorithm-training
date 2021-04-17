#include "03_01_02.cpp"

int main() {
  ThreeInOne tio(5);
  for (ll i = 10; i < 13; ++i) {
    tio.push(tio.s1, i);
  }
  for (ll i = 20; i < 23; ++i) {
    tio.push(tio.s2, i);
  }
  for (ll i = 30; i < 33; ++i) {
    tio.push(tio.s3, i);
  }
  printf("%s\n", tio.to_str().c_str());
  for (ll i = 10; i < 13; ++i) {
    printf("%lld\n", tio.pop(tio.s1));
  }
  for (ll i = 20; i < 23; ++i) {
    printf("%lld\n", tio.pop(tio.s2));
  }
  for (ll i = 30; i < 33; ++i) {
    printf("%lld\n", tio.pop(tio.s3));
  }
  printf("%s\n", tio.to_str().c_str());
  for (ll i = 50; i < 53; ++i) {
    tio.push(tio.s1, i);
  }
  printf("%s\n", tio.to_str().c_str());
  for (ll i = 50; i < 53; ++i) {
    printf("%lld\n", tio.pop(tio.s1));
  }
  printf("%s\n", tio.to_str().c_str());
  tio.pop(tio.s1);
}

//    [10 11 12  0  0 20 21 22  0  0 30 31 32  0  0]
// btm  ^              ^              ^
// pt            ^              ^              ^

// 12
// 11
// 10
// 22
// 21
// 20
// 32
// 31
// 30
//    [10 11 12  0  0 20 21 22  0  0 30 31 32  0  0]
// btm  ^              ^              ^
// pt   ^              ^              ^

//    [50 51 52  0  0 20 21 22  0  0 30 31 32  0  0]
// btm  ^              ^              ^
// pt            ^     ^              ^

// 52
// 51
// 50
//    [50 51 52  0  0 20 21 22  0  0 30 31 32  0  0]
// btm  ^              ^              ^
// pt   ^              ^              ^

// terminate called after throwing an instance of 'EmptyStackException'
//   what():  stack is empty
// Aborted
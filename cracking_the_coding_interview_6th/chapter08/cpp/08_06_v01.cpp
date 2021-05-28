// I have thought i can move a disk to only adjacent towers.
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

void move_right(vector<vector<ll>> &, ll);
void move_left(vector<vector<ll>> &, ll);

void show_towers(const vector<vector<ll>> &towers) {
  for (auto tower : towers) {
    cout << '[';
    for (ll i = 0; i < tower.size(); ++i) {
      cout << tower[i] << (i == tower.size() - 1 ? "" : " ");
    }
    cout << ']' << endl;
  }
  cout << endl;
}

void move_right(vector<vector<ll>> &towers, ll k) {
  if (k == 1) {
    ll x = towers[0].back();
    towers[0].pop_back();
    towers[1].push_back(x);
    show_towers(towers);
    x = towers[1].back();
    towers[1].pop_back();
    towers[2].push_back(x);
    show_towers(towers);
    return;
  }
  move_right(towers, k - 1);
  ll x = towers[0].back();
  towers[0].pop_back();
  towers[1].push_back(x);
  show_towers(towers);
  move_left(towers, k - 1);
  x = towers[1].back();
  towers[1].pop_back();
  towers[2].push_back(x);
  show_towers(towers);
  move_right(towers, k - 1);
}

void move_left(vector<vector<ll>> &towers, ll k) {
  if (k == 1) {
    ll x = towers[2].back();
    towers[2].pop_back();
    towers[1].push_back(x);
    show_towers(towers);
    x = towers[1].back();
    towers[1].pop_back();
    towers[0].push_back(x);
    show_towers(towers);
    return;
  }
  move_left(towers, k - 1);
  ll x = towers[2].back();
  towers[2].pop_back();
  towers[1].push_back(x);
  show_towers(towers);
  move_right(towers, k - 1);
  x = towers[1].back();
  towers[1].pop_back();
  towers[0].push_back(x);
  show_towers(towers);
  move_left(towers, k - 1);
}

void solve(ll n) {
  cout << "n=" << n << endl;
  vector<vector<ll>> towers(3);
  for (ll i = n; i > 0; --i) {
    towers[0].push_back(i);
  }
  show_towers(towers);
  move_right(towers, n);
}

int main() {
  solve(4);
}

// n=4
// [4 3 2 1]
// []
// []

// [4 3 2]
// [1]
// []

// [4 3 2]
// []
// [1]

// [4 3]
// [2]
// [1]

// [4 3]
// [2 1]
// []

// [4 3 1]
// [2]
// []

// [4 3 1]
// []
// [2]

// [4 3]
// [1]
// [2]

// [4 3]
// []
// [2 1]

// [4]
// [3]
// [2 1]

// [4]
// [3 1]
// [2]

// [4 1]
// [3]
// [2]

// [4 1]
// [3 2]
// []

// [4]
// [3 2 1]
// []

// [4]
// [3 2]
// [1]

// [4 2]
// [3]
// [1]

// [4 2]
// [3 1]
// []

// [4 2 1]
// [3]
// []

// [4 2 1]
// []
// [3]

// [4 2]
// [1]
// [3]

// [4 2]
// []
// [3 1]

// [4]
// [2]
// [3 1]

// [4]
// [2 1]
// [3]

// [4 1]
// [2]
// [3]

// [4 1]
// []
// [3 2]

// [4]
// [1]
// [3 2]

// [4]
// []
// [3 2 1]

// []
// [4]
// [3 2 1]

// []
// [4 1]
// [3 2]

// [1]
// [4]
// [3 2]

// [1]
// [4 2]
// [3]

// []
// [4 2 1]
// [3]

// []
// [4 2]
// [3 1]

// [2]
// [4]
// [3 1]

// [2]
// [4 1]
// [3]

// [2 1]
// [4]
// [3]

// [2 1]
// [4 3]
// []

// [2]
// [4 3 1]
// []

// [2]
// [4 3]
// [1]

// []
// [4 3 2]
// [1]

// []
// [4 3 2 1]
// []

// [1]
// [4 3 2]
// []

// [1]
// [4 3]
// [2]

// []
// [4 3 1]
// [2]

// []
// [4 3]
// [2 1]

// [3]
// [4]
// [2 1]

// [3]
// [4 1]
// [2]

// [3 1]
// [4]
// [2]

// [3 1]
// [4 2]
// []

// [3]
// [4 2 1]
// []

// [3]
// [4 2]
// [1]

// [3 2]
// [4]
// [1]

// [3 2]
// [4 1]
// []

// [3 2 1]
// [4]
// []

// [3 2 1]
// []
// [4]

// [3 2]
// [1]
// [4]

// [3 2]
// []
// [4 1]

// [3]
// [2]
// [4 1]

// [3]
// [2 1]
// [4]

// [3 1]
// [2]
// [4]

// [3 1]
// []
// [4 2]

// [3]
// [1]
// [4 2]

// [3]
// []
// [4 2 1]

// []
// [3]
// [4 2 1]

// []
// [3 1]
// [4 2]

// [1]
// [3]
// [4 2]

// [1]
// [3 2]
// [4]

// []
// [3 2 1]
// [4]

// []
// [3 2]
// [4 1]

// [2]
// [3]
// [4 1]

// [2]
// [3 1]
// [4]

// [2 1]
// [3]
// [4]

// [2 1]
// []
// [4 3]

// [2]
// [1]
// [4 3]

// [2]
// []
// [4 3 1]

// []
// [2]
// [4 3 1]

// []
// [2 1]
// [4 3]

// [1]
// [2]
// [4 3]

// [1]
// []
// [4 3 2]

// []
// [1]
// [4 3 2]

// []
// []
// [4 3 2 1]

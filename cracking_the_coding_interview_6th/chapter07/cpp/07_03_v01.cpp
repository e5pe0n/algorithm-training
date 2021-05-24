#include <stdexcept>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

class Music {
  string _title;

public:
  Music() {}
  Music(const string &title) : _title(title) {}
  void play() {}
};

class Jukebox {
  vector<Music> _play_list;
  ll _coins = 0;

public:
  Jukebox(const vector<Music> &play_list) : _play_list(play_list) {}
  void play(ll music_no) {
    if (_coins == 0)
      throw runtime_error{"num of coins is 0. please insert coins!"};
    _play_list[music_no].play();
    --_coins;
  }
  void insert_coin() {
    ++_coins;
  }
  void insert_coins(ll num) {
    _coins += num;
  }
};

int main() {}
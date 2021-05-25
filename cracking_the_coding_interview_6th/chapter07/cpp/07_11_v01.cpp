#include <memory>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

class BaseFile {
  ll _id;
  string _name;

public:
  BaseFile(ll id, string name) : _id(id), _name(name) {}
  ll id() {
    return _id;
  }
  string name() {
    return _name;
  }
  virtual ll size() = 0;
};

class File : public BaseFile {
public:
  File(ll id, string name, string contents)
      : contents(contents), BaseFile(id, name) {}
  string contents;
  ll size() override {
    return contents.size();
  }
};

using FilePtr = shared_ptr<BaseFile>; // run-time porymorphism needs pointers

class Directory : public BaseFile {
  ll _size = -1; // -1 indicates size is not cached.

public:
  Directory(ll id, string name, vector<FilePtr> contents)
      : contents(contents), BaseFile(id, name){};
  vector<FilePtr> contents;
  ll size() override {
    if (_size >= 0) return _size;
    _size = 0;
    for (const auto &f : contents) {
      _size += f->size();
    }
    return _size;
  }
  bool remove(ll id) {
    for (ll i = 0; i < _size; ++i) {
      if (contents[i]->id() == id) {
        contents.erase(contents.begin() + i);
        _size = -1;
        return true;
      }
    }
    return false;
  }
  void add(FilePtr f) {
    contents.push_back(f);
    _size = -1;
  }
};

int main() {}
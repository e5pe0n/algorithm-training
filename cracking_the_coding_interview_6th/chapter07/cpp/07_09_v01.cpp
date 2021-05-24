// this version's CircularArray cannot be applied to STL algorithms such as
// sort()
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

template <typename T> class CircularArray {
  vector<T> v;
  ll offset = 0;

  using It = decltype(v.begin());

public:
  template <typename Iter>
  struct CIterator
      : public iterator<typename iterator_traits<Iter>::iterator_category,
                        typename iterator_traits<Iter>::value_type,
                        typename iterator_traits<Iter>::difference_type,
                        typename iterator_traits<Iter>::pointer,
                        typename iterator_traits<Iter>::reference> {
    using traits_type = iterator_traits<Iter>;
    using difference_type = typename traits_type::difference_type;
    using pointer = typename traits_type::pointer;
    using reference = typename traits_type::reference;

    CIterator(Iter curr, Iter begin, Iter end, ll idx, ll offset, ll size)
        : curr(curr),
          begin(begin),
          end(end),
          idx(idx),
          offset(offset),
          size(size) {}
    template <typename Iter2>
    CIterator(const CIterator<Iter2> &it)
        : curr(it.curr),
          begin(it.begin),
          end(it.end),
          idx(it.idx),
          offset(it.offset),
          size(it.size) {}

    reference &operator*() const {
      return *curr;
    }
    pointer *operator->() {
      return curr;
    }

    CIterator &operator++() {
      ++curr, ++idx;
      if (idx >= size)
        curr = end;
      else if (idx + offset == size)
        curr = begin;
      return *this;
    }

    CIterator operator++(int) {
      CIterator res(*this);
      ++(*this);
      return res;
    }

    CIterator &operator--() {
      --curr, --idx;
      if (idx < 0) {
        curr = end;
        idx = size;
      } else if ((idx + offset) % size == size - 1)
        curr = end - 1;
    }

    CIterator operator--(int) {
      CIterator res(*this);
      --(*this);
      return res;
    }

    CIterator &operator+=(difference_type n) {
      curr += n;
      idx += n;
      if (idx >= size) {
        curr = end;
        idx = size;
      } else if (idx + offset >= size)
        curr = begin + (idx + offset) % size;
      return *this;
    }
    CIterator operator+(difference_type n) const {
      CIterator res{*this};
      res += n;
      return res;
    }
    CIterator &operator-=(difference_type n) {
      curr -= n;
      idx -= n;
      if (idx < 0) {
        curr = end;
        idx = size;
      } else if ((idx + offset) % size == size - 1)
        curr = end - 1;
      return *this;
    }
    CIterator operator-(difference_type n) const {
      CIterator res{*this};
      res -= n;
      return res;
    }
    reference operator[](difference_type n) const {
      tmp = this + n;
      return *tmp;
    }

    friend bool operator==(const CIterator &it1, const CIterator &it2) {
      return it1.curr == it2.curr;
    }

    friend bool operator!=(const CIterator &it1, const CIterator &it2) {
      return it1.curr != it2.curr;
    }
    friend bool operator<(const CIterator &it1, const CIterator &it2) {
      return it1.curr < it2.curr;
    }

  private:
    Iter curr;
    Iter begin;
    Iter end;
    ll idx;
    ll offset;
    ll size;
    Iter tmp;
  };

  CircularArray() {}
  CircularArray(initializer_list<T> args) {
    v = vector<T>(args.begin(), args.end());
  }
  CircularArray(size_t n, const T &val) {
    v = vector<T>(n, val);
  }
  ll size() {
    return v.size();
  }
  CIterator<It> make_CIterator(It curr, ll idx) {
    return CIterator(curr, v.begin(), v.end(), idx, offset, size());
  }
  CIterator<It> begin() {
    return make_CIterator(v.begin() + offset, 0);
  }
  CIterator<It> end() {
    return make_CIterator(v.end(), size());
  }
  ll last_idx() {
    return (offset + size() - 1) % size();
  }
  void inc_offset() {
    offset = (offset + 1) % size();
  }
  void dec_offset() {
    offset = ((offset - 1) % size() + size()) % size();
  }
  T &operator[](size_t idx) {
    return *(begin() + idx);
  }
  const T &operator[](size_t idx) const {
    return *(begin() + idx);
  }
  void rotate_right() {
    dec_offset();
  }
  void rotate_left() {
    inc_offset();
  }
  void push_back(const T &x) {
    v.push_back(x);
  }
  void pop_back() {
    v.pop_back();
  }
};

int main() {
  CircularArray<ll> ca{10, 11, 12, 13, 14};
  for (auto n : ca) {
    cout << n << ' ';
  }
  cout << endl;
  // 10 11 12 13 14

  ca.rotate_right();
  for (auto n : ca) {
    cout << n << ' ';
  }
  cout << endl;
  // 14 10 11 12 13

  ca.rotate_left();
  ca.rotate_left();
  ca.rotate_left();
  for (auto n : ca) {
    cout << n << ' ';
  }
  cout << endl;
  // 12 13 14 10 11

  for (ll i = 0; i < ca.size(); ++i) {
    cout << ca[i] << ' ';
  }
  cout << endl;
  // 12 13 14 10 11

  ca.push_back(100);
  ca.push_back(200);
  for (auto n : ca) {
    cout << n << ' ';
  }
  cout << endl;
  // 12 13 14 100 200 10 11

  ca.pop_back();
  for (auto n : ca) {
    cout << n << ' ';
  }
  cout << endl;
  // 12 13 14 100 10 11

  ca[1] = 999;
  for (auto n : ca) {
    cout << n << ' ';
  }
  cout << endl;
  // 12 999 14 100 10 11
}

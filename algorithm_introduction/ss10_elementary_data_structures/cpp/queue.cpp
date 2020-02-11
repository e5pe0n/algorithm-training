#include <iostream>
#include <string>

using namespace std;

struct _Queue {
  // To distinguish between underflow and overflow, _Queue have an empty element in arr.
  // i.e. arr whose capacity is _capacity needs size which is _capacity + 1.
  int _capacity;
  int _size;
  int *_arr;
  int _head = 0;
  int _tail = 0;

  _Queue(int capacity) : _capacity(capacity), _size(capacity + 1) { _arr = new int[_size]; }

  string _arr_str() {
    string s = "[";
    if (_head <= _tail) {
      for (int i = _head; i < _tail; ++i) {
        s += to_string(_arr[i]);
        s += ", ";
      }
    } else {
      for (int i = _head; i < _capacity; ++i) {
        s += to_string(_arr[i]);
        s += ", ";
      }
      for (int i = 0; i <= _head; ++i) {
        s += to_string(_arr[i]);
        s += ", ";
      }
    }
    s += "]";
    return s;
  }

  bool _queue_empty() { return _head == _tail; }
  bool _queue_full() {
    int tail_next = _tail + 1;
    if (tail_next == _size)
      tail_next = 0;
    return tail_next == _head;
  }

  void _enqueue(int x) {
    if (_queue_full())
      throw "Overflow";
    _arr[_tail++] = x;
    if (_tail == _size)
      _tail = 0;
  }

  int _dequeue() {
    if (_queue_empty())
      throw "Underflow";
    int x = _arr[_head++];
    if (_head == _size)
      _head = 0;
    return x;
  }

  ~_Queue() { delete[] _arr; }
};

int main() {
  _Queue Q(3);

  try {
    Q._dequeue(); // underflow
  } catch (char const *e) {
    cout << "Error: " << e << endl;
  }
  Q._enqueue(1);
  Q._enqueue(2);
  Q._enqueue(3);
  try {
    Q._enqueue(4);
  } catch (char const *e) {
    cout << "Error: " << e << endl;
  }
  cout << "Q._arr_str(): " << Q._arr_str() << "\n";
  cout << "Q._dequeue(): " << to_string(Q._dequeue()) << "\n";
  cout << "Q._arr_str(): " << Q._arr_str() << "\n";
  Q._enqueue(5);
  cout << "Q._arr_str(): " << Q._arr_str() << "\n";
  cout << "Q._dequeue(): " << to_string(Q._dequeue()) << "\n";
  cout << "Q._arr_str(): " << Q._arr_str() << "\n";
  Q._enqueue(5);
  cout << "Q._arr_str(): " << Q._arr_str() << "\n";
  cout << "Q._dequeue(): " << to_string(Q._dequeue()) << "\n";
}
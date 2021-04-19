#include <exception>
#include <list>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

class Animal {
public:
  ll idx;
  Animal(ll _idx) : idx(_idx) {}
  virtual string to_str() {
    return "Animal: " + to_string(idx);
  }
};

class Dog : public Animal {
public:
  Dog(ll _idx) : Animal(_idx) {}
  string to_str() override {
    return "Dog: " + to_string(idx);
  }
};

class Cat : public Animal {
public:
  Cat(ll _idx) : Animal(_idx) {}
  string to_str() override {
    return "Cat: " + to_string(idx);
  }
};

class EmptyQueueException : public exception {
  virtual const char *what() const throw() {
    return "queue is empty";
  }
} eqe;

class AnimalShelter {
private:
  template <class T> struct Data {
    ll ord;
    T obj;
  };

  ll cnt = 0;
  list<Data<Dog *>> dog_q;
  list<Data<Cat *>> cat_q;

public:
  ll size() {
    return dog_q.size() + cat_q.size();
  }

  bool is_empty() {
    return size() == 0;
  }

  void enqueue(Animal *x) {
    if (Dog *d = dynamic_cast<Dog *>(x)) {
      dog_q.push_back(Data<Dog *>{cnt, d});
      ++cnt;
    }
    if (Cat *c = dynamic_cast<Cat *>(x)) {
      cat_q.push_back(Data<Cat *>{cnt, c});
      ++cnt;
    }
  }

  Animal *dequeue_any() {
    if (is_empty()) throw eqe;
    if (cat_q.size() == 0) {
      Dog *d = dog_q.front().obj;
      dog_q.pop_front();
      return d;
    }
    if (dog_q.size() == 0) {
      Cat *c = cat_q.front().obj;
      cat_q.pop_front();
      return c;
    }
    if (cat_q.front().ord > dog_q.front().ord) {
      Dog *d = dog_q.front().obj;
      dog_q.pop_front();
      return d;
    } else {
      Cat *c = cat_q.front().obj;
      cat_q.pop_front();
      return c;
    }
  }

  Dog *dequeue_dog() {
    if (dog_q.size() == 0) throw eqe;
    Dog *d = dog_q.front().obj;
    dog_q.pop_front();
    return d;
  }

  Cat *dequeue_cat() {
    if (cat_q.size() == 0) throw eqe;
    Cat *c = cat_q.front().obj;
    cat_q.pop_front();
    return c;
  }
};

string animal_str(Animal *x) {
  string res = "failed";
  if (Dog *d = dynamic_cast<Dog *>(x)) res = d->to_str();
  if (Cat *c = dynamic_cast<Cat *>(x)) res = c->to_str();
  return res;
}

int main() {
  vector<Animal *> v{new Dog(1),
                     new Cat(2),
                     new Dog(3),
                     new Dog(4),
                     new Dog(5),
                     new Cat(6),
                     new Cat(7),
                     new Cat(8),
                     new Dog(9),
                     new Cat(10),
                     new Dog(11),
                     new Cat(12),
                     new Dog(13)};

  AnimalShelter as;
  for (auto a : v)
    as.enqueue(a);

  printf("%s\n", animal_str(as.dequeue_any()).c_str());
  printf("%s\n", animal_str(as.dequeue_any()).c_str());
  printf("%s\n", animal_str(as.dequeue_any()).c_str());
  puts("");

  printf("%s\n", as.dequeue_cat()->to_str().c_str());
  printf("%s\n", as.dequeue_cat()->to_str().c_str());
  printf("%s\n", as.dequeue_cat()->to_str().c_str());
  puts("");

  printf("%s\n", as.dequeue_dog()->to_str().c_str());
  printf("%s\n", as.dequeue_dog()->to_str().c_str());
  puts("");

  printf("%s\n", as.dequeue_cat()->to_str().c_str());
  printf("%s\n", as.dequeue_dog()->to_str().c_str());
  printf("%s\n", as.dequeue_cat()->to_str().c_str());
  puts("");

  while (!as.is_empty()) {
    printf("%s\n", animal_str(as.dequeue_any()).c_str());
  }
}

// Dog: 1
// Cat: 2
// Dog: 3

// Cat: 6
// Cat: 7
// Cat: 8

// Dog: 4
// Dog: 5

// Cat: 10
// Dog: 9
// Cat: 12

// Dog: 11
// Dog: 13
#include <thread>

using namespace std;

// function
void foo(int Z) {
  for (int i = 0; i < Z; ++i) {
    printf("Thread using function pointer as callable\n");
  }
}

// callable object
class thread_obj {
public:
  void operator()(int x) {
    for (int i = 0; i < x; ++i) {
      printf("Thread using function object as callable\n");
    }
  }
};

int main() {
  printf("Threads 1 and 2 and 3 operating independently\n");

  // launch a thread using function pointer as callable
  thread th1(foo, 3);

  // launch a thread using function object as callable
  thread th2(thread_obj(), 3);

  auto f = [](int x) {
    for (int i = 0; i < x; ++i) {
      printf("Thread using lambda expression as callable\n");
    }
  };

  // launch a thread using lambda expression as callable
  thread th3(f, 3);

  th1.join();
  th2.join();
  th3.join();
}

// Threads 1 and 2 and 3 operating independently
// Thread using function pointer as callable
// Thread using function object as callable
// Thread using lambda expression as callable
// Thread using lambda expression as callable
// Thread using lambda expression as callable
// Thread using function object as callable
// Thread using function object as callable
// Thread using function pointer as callable
// Thread using function pointer as callable
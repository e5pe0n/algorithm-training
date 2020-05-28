#include <chrono>
#include <future>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  future<string> fu = async([&] {
    this_thread::sleep_for(chrono::seconds(5));
    return string("Some Message");
  });

  auto cons = thread([&] { printf("%s\n", fu.get().c_str()); });

  cons.join();
}
#include <chrono>
#include <future>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  auto prom = promise<string>();
  auto fu = prom.get_future();

  auto prod = thread([&] {
    this_thread::sleep_for(chrono::seconds(5));
    prom.set_value("Some Message");
  });
  auto cons = thread([&] { printf("%s\n", fu.get().c_str()); });

  prod.join();
  cons.join();
}
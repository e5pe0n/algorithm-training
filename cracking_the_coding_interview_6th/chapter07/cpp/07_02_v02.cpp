// Cracking the Coding Interview p.308
#include <list>
#include <memory>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

enum class Rank { responder = 0, manager, director };

class Employee;
class Call;
class CallHandler;

using EmployeePtr = shared_ptr<Employee>;
using CallPtr = shared_ptr<Call>;
using CallerPtr = shared_ptr<Caller>;

class Caller {};

class Employee {
  CallPtr _current_call = nullptr;

protected:
  Rank _rank;

public:
  Employee(CallHandler handler);
  void recieve_call(Call call);
  void call_completed();
  void escalate_and_reassign();
  bool assign_new_call();
  bool is_free() {
    return _current_call != nullptr;
  }
  Rank rank() {
    return _rank;
  }
};

class Director : public Employee {
public:
  Director(CallHandler handler) : Employee(handler) {
    _rank = Rank::director;
  }
};

class Manager : public Employee {
public:
  Manager(CallHandler handler) : Employee(handler) {
    _rank = Rank::manager;
  }
};

class Responder : public Employee {
public:
  Responder(CallHandler handler) : Employee(handler) {
    _rank = Rank::responder;
  }
};

class Call {
  Rank _rank;
  CallerPtr _caller;
  EmployeePtr _handler;

public:
  Call(CallerPtr c) : _rank(Rank::responder), _caller(c) {}

  void set_handler(EmployeePtr e) {
    _handler = e;
  }

  void reply(string message);
  Rank rank() {
    return _rank;
  }
  void set_rank(Rank r) {
    _rank = r;
  }
  Rank incrementRank();
  void disconnect();
};

class CallHandler {
  const ll LEVELS = 3;

  const ll NUM_RESPONDENTS = 10;
  const ll NUM_MANAGERS = 4;
  const ll NUM_DIRECTORS = 3;

  vector<vector<EmployeePtr>> employee_levels;
  vector<list<Call>> call_queues;

public:
  CallHandler(){};

  EmployeePtr get_handler_for_call(Call call);

  void dispatch_call(Caller caller) {
    Call call{make_shared<Caller>(caller)};
    dispatch_call(call);
  }

  void dispatch_call(Call call) {
    EmployeePtr emp = get_handler_for_call(call);
    if (emp) {
      emp->recieve_call(call);
      call.set_handler(emp);
    } else {
      call.reply("Please wait for free employee to reply");
      call_queues[static_cast<ll>(call.rank())].push_back(call);
    }
  }

  bool assign_and_call(Employee emp);
};

int main() {}
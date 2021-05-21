// Cracking the Coding Interview p.308
#include <list>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

enum class Rank { responder = 0, manager, director };

class Employee;
class Call {};
class CallHandler;

class Caller {};

class Employee {
  Call _current_call;
  bool _is_free;

protected:
  Rank _rank;

public:
  Employee() {}
  Employee(CallHandler handler);
  void recieve_call(Call call);
  void call_completed();
  void escalate_and_reassign();
  bool assign_new_call();
  bool is_free() {
    return _is_free;
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
  Caller _caller;
  Employee _handler;

public:
  Call(Caller c) : _rank(Rank::responder), _caller(c) {}

  void set_handler(Employee e) {
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

  vector<vector<Employee>> employee_levels;
  vector<list<Call>> call_queues;

  struct HandlerRes {
    bool valid = false;
    Employee emp;
  };

public:
  CallHandler(){};

  HandlerRes get_handler_for_call(Call call);

  void dispatch_call(Caller caller) {
    Call call{caller};
    dispatch_call(call);
  }

  void dispatch_call(Call call) {
    HandlerRes res = get_handler_for_call(call);
    if (res.valid) {
      res.emp.recieve_call(call);
      call.set_handler(res.emp);
    } else {
      call.reply("Please wait for free employee to reply");
      call_queues[static_cast<ll>(call.rank())].push_back(call);
    }
  }

  bool assign_and_call(Employee emp);
};

int main() {}
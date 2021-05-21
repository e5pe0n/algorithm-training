#include <type_traits>
#include <vector>
using namespace std;
using ll = long long;

class Task {
  ll _id;

public:
  ll id() {
    return _id;
  }
};

class Employee {
public:
  bool can_handle(Task task);
};

class Respondent : public Employee {};

class Manager : public Employee {};

class Director : public Employee {};

template <typename T> class AssignmentTable {
  static_assert(is_base_of_v<Employee, T>, "T must be derived from Employee.");
  vector<T> frees;
  map<Task, T> assigneds;

public:
  void push_free(T t) {
    frees.push_back(t);
  }

  ll frees_size() {
    return freese.size();
  }

  T pop_free() {
    return frees.pop_back();
  }

  void assign(T t, Task task) {
    assigneds[task] = t;
  }
};

class CallCenter {
  AssignmentTable<Respondent> respondents;
  AssignmentTable<Manager> managers;
  AssignmentTable<Director> directors;

  ll task_id = 0;

  void _assign(Respondent respondent) {
    respondents.assign(respondent, task);
  }

  void _assign(Manager manager) {
    mangers.assign(manager, task);
  }

  void _assign(Director director) {
    directors.assign(director, task);
  }

  template <typename T> bool assign(T t, Task task) {
    static_assert(is_base_of_v<Employee, T>,
                  "T must be derived from Employee.");
    if (t.can_handle()) {
      _assign(t);
      return true;
    }
    return false;
  }

  template <typename T> bool escalate_to(Task task);

  template <> bool escalate_to<Director>(Task task) {
    if (!directors.free_size()) return false;
    return assign(directors.pop_free(), task);
  }

  template <> bool escalate_to<Manager>(Task task) {
    if (!managers.frees_size()) return escalate_to<Director>(task);
    if (assign(managers.pop_free(), task)) return true;
    return escalate_to<Director>(task);
  }

public:
  bool dispatch_call() {
    Task task{task_id++};
    if (!respondents.frees_size()) return escalate_to<Manger>(task);
    if (assign(respondents.pop_free(), task)) return true;
    return escalate_to<Manager>(task);
  }
};

int main() {}
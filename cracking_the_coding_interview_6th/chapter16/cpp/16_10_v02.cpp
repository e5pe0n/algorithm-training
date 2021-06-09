// Cracking the Coding Interview p.486
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

struct Person {
  ll birth, dead;
};

vector<ll> get_population_deltas(const vector<Person> &people, ll mi, ll ma) {
  vector<ll> population_deltas(ma - mi + 2);
  for (const auto &p : people) {
    ++population_deltas[p.birth - mi];
    --population_deltas[p.dead + 1 - mi];
  }
  return population_deltas;
}

ll get_max_alive_year(vector<ll> deltas) {
  ll max_alive_year = 0;
  ll max_alive = 0;
  ll curr_alive = 0;
  for (ll year = 0; year < deltas.size(); ++year) {
    curr_alive += deltas[year];
    if (curr_alive > max_alive) {
      max_alive_year = year;
      max_alive = curr_alive;
    }
  }
  return max_alive_year;
}

ll max_alive_year(vector<Person> people, ll mi, ll ma) {
  vector<ll> population_deltas = get_population_deltas(people, mi, ma);
  ll res = get_max_alive_year(population_deltas);
  return res + mi;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs(fp);
  ll n;
  ifs >> n;
  vector<Person> people(n);
  for (ll i = 0; i < n; ++i) {
    ll birth, dead;
    ifs >> birth >> dead;
    people[i] = Person{birth, dead};
  }
  printf("%lld\n", max_alive_year(people, 1900, 2000));
  puts("");
}

int main() {
  solve("../testcases/16_10/01.txt");
  solve("../testcases/16_10/02.txt");
}

// # ../testcases/16_10/01.txt
// 1935

// # ../testcases/16_10/02.txt
// 1964

#include <fstream>
#include <map>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

map<pll, double> calc_similarity(map<ll, vector<ll>> &docs) {
  map<ll, vector<ll>> w2d;
  for (const auto &[id, words] : docs) {
    for (const auto v : words) {
      w2d[v].push_back(id);
    }
  }
  map<pll, ll> cnt_intersection;
  for (const auto &[_, ids] : w2d) {
    for (ll i = 0; i < ids.size(); ++i) {
      for (ll j = i + 1; j < ids.size(); ++j) {
        ++cnt_intersection[{ids[i], ids[j]}];
      }
    }
  }
  map<pll, double> simiralities;
  for (const auto [ids, n_intersection] : cnt_intersection) {
    ll n_union = (ll)docs[ids.first].size() + (ll)docs[ids.second].size()
                 - n_intersection;
    simiralities[ids] = (double)n_intersection / n_union;
  }
  return simiralities;
}

void solve(const string &fp) {
  printf("# %s\n", fp.c_str());
  ifstream ifs{fp};
  ll n_docs;
  ifs >> n_docs;
  map<ll, vector<ll>> docs;
  for (ll i = 0; i < n_docs; ++i) {
    ll id, n_words;
    ifs >> id >> n_words;
    docs[id] = vector<ll>(n_words);
    for (ll j = 0; j < n_words; ++j) {
      ifs >> docs[id][j];
    }
  }
  // for (auto [id, words] : docs) {
  //   printf("id=%lld: ", id);
  //   for (auto v : words) {
  //     printf("%lld ", v);
  //   }
  //   puts("");
  // }
  map<pll, double> res = calc_similarity(docs);
  for (const auto &[ids, sim] : res) {
    printf("(%lld, %lld): %f\n", ids.first, ids.second, sim);
  }
  puts("");
}

int main() {
  solve("../testcases/17_26/01.txt");
  solve("../testcases/17_26/02.txt");
  solve("../testcases/17_26/03.txt");
}

// # ../testcases/17_26/01.txt
// (13, 16): 0.250000
// (13, 19): 0.100000
// (19, 24): 0.142857

// # ../testcases/17_26/02.txt
// (0, 9): 0.018519
// (2, 3): 0.009009
// (3, 9): 0.006623
// (5, 8): 0.016949
// (8, 9): 0.007353

// # ../testcases/17_26/03.txt
// (0, 92): 0.007752
// (1, 40): 0.009091
// (2, 3): 0.006173
// (2, 12): 0.006803
// (2, 36): 0.008547
// (2, 42): 0.009524
// (2, 91): 0.005988
// (3, 13): 0.006579
// (3, 38): 0.007194
// (3, 88): 0.005952
// (5, 6): 0.010309
// (6, 13): 0.007937
// (6, 79): 0.006250
// (7, 13): 0.008475
// (7, 33): 0.006623
// (7, 98): 0.008065
// (9, 20): 0.008065
// (9, 94): 0.007463
// (12, 52): 0.007752
// (12, 86): 0.006711
// (13, 29): 0.011111
// (13, 78): 0.007576
// (14, 46): 0.010309
// (17, 51): 0.015385
// (20, 74): 0.008130
// (21, 97): 0.076923
// (22, 33): 0.007634
// (24, 26): 0.012821
// (24, 32): 0.010638
// (24, 90): 0.008264
// (25, 34): 0.007092
// (25, 45): 0.015873
// (25, 77): 0.008403
// (25, 94): 0.009901
// (27, 40): 0.009174
// (27, 77): 0.011111
// (29, 39): 0.017857
// (29, 47): 0.015152
// (29, 54): 0.010101
// (32, 33): 0.007519
// (32, 78): 0.009709
// (32, 88): 0.008621
// (33, 39): 0.005405
// (33, 78): 0.006061
// (33, 81): 0.008929
// (33, 83): 0.005495
// (34, 63): 0.008547
// (34, 99): 0.008000
// (35, 46): 0.013889
// (35, 98): 0.012195
// (37, 67): 0.009615
// (37, 68): 0.006211
// (37, 75): 0.006803
// (38, 40): 0.014085
// (38, 54): 0.008000
// (38, 83): 0.007353
// (39, 85): 0.006135
// (40, 48): 0.006173
// (41, 72): 0.010526
// (42, 62): 0.019608
// (42, 74): 0.009174
// (42, 92): 0.007812
// (44, 70): 0.026316
// (44, 82): 0.022222
// (46, 57): 0.014085
// (46, 88): 0.007092
// (46, 98): 0.007634
// (47, 74): 0.008403
// (48, 98): 0.007092
// (50, 54): 0.007143
// (50, 58): 0.007194
// (50, 91): 0.006289
// (51, 52): 0.009091
// (51, 59): 0.006711
// (51, 88): 0.007463
// (54, 91): 0.006024
// (57, 58): 0.012048
// (58, 79): 0.005848
// (58, 88): 0.006536
// (59, 62): 0.008621
// (59, 72): 0.005618
// (59, 83): 0.005556
// (63, 80): 0.012195
// (66, 92): 0.008065
// (68, 88): 0.005988
// (69, 93): 0.032258
// (70, 94): 0.012500
// (72, 92): 0.005556
// (74, 85): 0.006494
// (74, 86): 0.006452
// (74, 90): 0.007092
// (74, 91): 0.005848
// (74, 94): 0.007519
// (75, 79): 0.005848
// (78, 99): 0.010204
// (79, 90): 0.006211
// (84, 98): 0.008696
// (85, 92): 0.005780
// (85, 94): 0.007692
// (85, 99): 0.009434
// (88, 99): 0.009009
// (90, 98): 0.007519
// (91, 98): 0.006135
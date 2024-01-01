#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

ll n, k;
vl A;
vl S;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n >> k;

  A = vl(n + 1);
  for (auto i = 1; i <= n; ++i) {
    cin >> A[i];
  }

  S = vl(n + 1, 0);
  for (auto i = 1; i <= n; ++i) {
    S[i] = S[i - 1] + A[i];
  }

  auto ans = numeric_limits<ll>::min();
  for (auto i = k; i <= n; ++i) {
    ans = max(ans, S[i] - S[i - k]);
  }

  cout << ans;

  return 0;
}
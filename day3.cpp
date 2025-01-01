#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vpii = vector<pii>;
 
const int dr[4] = {1,0,-1,0};
const int dc[4] = {0,1,0,-1};
const int MOD = 1e9+7;
const ll INF = 1e18; // not too close to LLONG_MAX
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
template<typename T> using ordered_set = 
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxN = 200000;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string line;
    ll res=0, tmp=1;
    std::regex mul_regex("mul\\(([0-9]{1,3}),([0-9]{1,3})\\)|do\\(\\)|don't\\(\\)");

    while(getline(cin, line)) {
      string s(line);
      auto words_begin = std::sregex_iterator(s.begin(), s.end(), mul_regex);
      auto words_end = std::sregex_iterator();

      for (std::sregex_iterator i = words_begin; i != words_end; i++) {
        std::smatch mul_match = *i;
        if (mul_match[0] == "do()") {
          tmp = 1;
          continue;
        }
        if (mul_match[0] == "don't()") {
          tmp = 0;
          continue;
        }
        res += stoi(mul_match[1])*stoi(mul_match[2])*tmp;
      }
    }
    cout << res << endl;
    return 0;
}
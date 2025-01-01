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

vector<int> split(const string& s, char c) {
  vector<string> res;
  string::size_type prev_pos = 0, pos = 0;
  while((pos = s.find(c, pos)) != string::npos) {
    string substring(s.substr(prev_pos, pos-prev_pos));
    res.push_back(stoi(substring));
    prev_pos = ++pos;
  }
  res.push_back(stoi(s.substr(prev_pos, pos-prev_pos))); // Last word
  return res;
}

bool isSafe(string s) {
  vector<int> numbers = split(s, ' ');
  if (numbers[0] == numbers[1]) return false;
  int sign = numbers[0] > numbers[1] ? -1 : 1;
  for(int i=0; i<numbers.size() - 1; i++) {
    
  }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s;
    ll res=0;
    while(cin >> s) {
      cout << s << endl;
    }
    return 0;
}
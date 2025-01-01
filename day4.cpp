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

const int dr[8] = {-1,-1,-1,0,0,1,1,1};
const int dc[8] = {-1,0,1,-1,1,-1,0,1};

const int MOD = 1e9+7;
const ll INF = 1e18; // not too close to LLONG_MAX
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
template<typename T> using ordered_set = 
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<string> graph;
int maxR = 0, maxC = 0;

bool isValid(int r, int c) {
  return (r >= 0 && r < maxR && c >= 0 && c < maxC);
}

ll isXMAS() {
  ll res=0;
  for (int r=0; r<graph.size(); ++r)
    for (int c=0; c<graph[r].size(); ++c)
      if (graph[r][c] == 'X') {
        // cout << "Xr=" << r << ", Xc=" << c << endl;
        for (int i=0; i<8; ++i) {
          for (int z=1; z<=3; ++z) {
            int nr = r + dr[i]*z;
            int nc = c + dc[i]*z;
            if (isValid(nr, nc)) {
              // cout << "nr=" << nr << ", nc=" << nc << endl;
              if (z == 1) {
                if (graph[nr][nc] != 'M') break;
              } else if (z == 2) {
                if (graph[nr][nc] != 'A') break;
              } else if (z == 3) {
                if (graph[nr][nc] == 'S') res+=1;
              }
            }
          }
        }
      }

  return res;
}

ll isX_MAS() {
  ll res=0;
  for (int r=0; r<graph.size()-2; ++r)
    for (int c=0; c<graph[r].size()-2; ++c) {
      string dig1 = string(1,graph[r][c]) + graph[r+1][c+1] + graph[r+2][c+2];
      string dig2 = string(1,graph[r][c+2]) + graph[r+1][c+1] + graph[r+2][c];
      if ((dig1 == "MAS" || dig1 == "SAM") && (dig2 == "MAS" || dig2 == "SAM"))
        res+=1;
    }
  return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string line;
  
  while(getline(cin, line)) {
    graph.push_back(line);
    ++maxR;
    maxC = line.length();
  }
  
  cout << isX_MAS() << endl;
  return 0;
}
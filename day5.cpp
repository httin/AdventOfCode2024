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

vector<int> split(const string& s, char c) {
  vector<int> res;
  string::size_type prev_pos = 0, pos = 0;
  while((pos = s.find(c, pos)) != string::npos) {
    res.push_back(stoi(s.substr(prev_pos, pos-prev_pos)));
    prev_pos = ++pos;
  }
  res.push_back(stoi(s.substr(prev_pos, pos-prev_pos))); // Last word
  return res;
}


void dfs(int u, vector<vector<int>>& graph, vector<int>& visited, vector<int>& result) {
  visited[u] = 1;
  for (auto v : graph[u]) {
    if (visited[v] == 1) {
      cout << "Error: graph contains a cycle u=" << u << ", v=" << v << endl;
      exit(0);
    }
    if (!visited[v]) {
      dfs(v, graph, visited, result);
    }
  }
  result.push_back(u);
  visited[u] = 2;
}

void topoSort(vector<vector<int>>& graph, vector<int>& result) {
  vector<int> visited(100, 0);
  for (int i=0; i<100; i++) {
    if (!visited[i])
      dfs(i, graph, visited, result);
  }
  reverse(result.begin(), result.end());
}

bool check(const vector<vector<int>> &graph, vector<int> &order) {
  for (int i=0; i<order.size()-1; i++) {
    for (int j=i+1; j<order.size(); j++) {
      int u = order[i];
      if(find(graph[u].begin(), graph[u].end(), order[j]) == graph[u].end())
        return false;
    }
  }
  return true;
}

bool checkAndSort(const vector<vector<int>> &graph, vector<int> &order) {
  bool ret = false; // only find incorrectly-ordered
  for (int i=0; i<order.size(); i++) {
    for (int j=i+1; j<order.size(); j++) {
      int u = order[i];
      if(find(graph[u].begin(), graph[u].end(), order[j]) == graph[u].end()) {
        ret = true;
        int tmp = order[j];
        for (int k=j; k>=i+1; k--)
          order[k] = order[k-1];
        order[i] = tmp;
      }
    }
  }
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string line;
  ll res=0;
  vector<vector<int>> graph(100, vector<int>());
  while(getline(cin, line)) {
    if (line.empty()) break;
    vector<int> numbers = split(line, '|');
    graph[numbers[0]].push_back(numbers[1]);
  }
  // for (int u=0; u<100; ++u)
  //   for (auto v : graph[u])
  //     cout << "u=" << u << ", v=" << v << endl;
  while(getline(cin, line)) {
    if (line.empty()) break;
    vector<int> order = split(line, ',');
    if (checkAndSort(graph, order)) {
      cout << line << endl;
      for (auto o : order) cout << o << ">";
      cout << endl;
      res += order[order.size()/2];
    }
  }

  cout << res << endl;
  return 0;
}
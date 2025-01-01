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

enum Dir {Up, Down, Right, Left};
int maxR = 0, maxC = 0;

bool isValid(int r, int c) {
  return (r >= 0 && r < maxR && c >= 0 && c < maxC);
}

bool isMovable(vector<string>& graph, int r, int c) {
  return graph[r][c] != '#';
}

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

bool move(vector<string>& graph, int& r, int& c, Dir& dir) {
  graph[r][c] = 'X';
  if (dir == Up) {
    if (!isValid(r-1, c)) return false;
    if (isMovable(graph, r-1, c)) {
      r--;
    } else {
      dir = Right;
    }
  } else if (dir == Right) {
    if (!isValid(r, c+1)) return false;
    if (isMovable(graph, r, c+1)) {
      c++;
    } else {
      dir = Down;
    }
  } else if (dir == Down) {
    if (!isValid(r+1, c)) return false;
    if (isMovable(graph, r+1, c)) {
      r++;
    } else {
      dir = Left;
    }
  } else if (dir == Left) {
    if (!isValid(r, c-1)) return false;
    if (isMovable(graph, r, c-1)) {
      c--;
    } else {
      dir = Up;
    }
  } else {
    cout << "[FATAL] Unexpected direction " << dir << endl;
  }
  return true;
}

bool move2(vector<string>& graph, int r, int c) {
  set<tuple<int, int, Dir>> seen{};
  Dir dir = Up;
  while(true) {
    tuple<int, int, Dir> cur = make_tuple(r, c, dir);
    if (seen.find(cur) != seen.end()) {
      return true;
    }
    seen.insert(cur);
    int dx, dy;
    if (dir == Up) {
      dx = -1;
      dy = 0;
    } else if (dir == Right) {
      dx = 0;
      dy = 1;
    } else if (dir == Down) {
      dx = 1;
      dy = 0;
    } else if (dir == Left) {
      dx = 0;
      dy = -1;
    } else {
      cout << "[FATAL] Unexpected direction " << dir << endl;
    }
    if (!isValid(r + dx, c + dy))
      break; // next move is out range, exit!
    while (graph[r + dx][c + dy] == '#') {
      if (dir == Up) {
        dir = Right;
      } else if (dir == Right) {
        dir = Down;
      } else if (dir == Down) {
        dir = Left;
      } else if (dir == Left) {
        dir = Up;
      }
      if (dir == Up) {
        dx = -1;
        dy = 0;
      } else if (dir == Right) {
        dx = 0;
        dy = 1;
      } else if (dir == Down) {
        dx = 1;
        dy = 0;
      } else if (dir == Left) {
        dx = 0;
        dy = -1;
      }
    }
    r += dx;
    c += dy;
    if (!isValid(r, c))
      break; // next move is out range, exit!
  }
  return false;
}

int part1(vector<string>& graph) {
  int res=0, curR, curC;
  Dir dir = Up;
  for (int r=0; r<maxR; r++) {
    for (int c=0; c<maxC; c++) {
      if (graph[r][c] == '^') {
        curR = r;
        curC = c;
        break;
      }
    }
  }
  cout << "[START] curR=" << curR << ", curC=" << curC << ", dir=" << dir << endl;
  while(move(graph, curR, curC, dir))
    ;
  cout << "[END] curR=" << curR << ", curC=" << curC << ", dir=" << dir << endl;
  for (int r=0; r<maxR; r++) {
    for (int c=0; c<maxC; c++)
      if (graph[r][c] == 'X')
        res++;
  }
  return res;
}

int part2(vector<string>& graph) {
  int res=0, curR, curC;
  for (int r=0; r<maxR; r++) {
    for (int c=0; c<maxC; c++) {
      if (graph[r][c] == '^') {
        curR = r;
        curC = c;
        break;
      }
    }
  }

  for (int r=0; r<maxR; r++) {
    for (int c=0; c<maxC; c++)
      if (graph[r][c] == '.') {
        graph[r][c] = '#';
        if(move2(graph, curR, curC)) {
          cout << "[SOLUTION] (" << r << "," << c << ")" << endl;
          res++;
        }
        graph[r][c] = '.';
      }
  }
  return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string line;
  vector<string> graph;
  while(getline(cin, line)) {
    if (line.empty()) break;
    graph.push_back(line);
  }
  maxR = graph.size();
  maxC = graph[0].size();

  cout << part2(graph) << endl;
  return 0;
}
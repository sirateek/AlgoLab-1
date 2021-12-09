#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> graph[3010];
bool seens[3010];

bool is_possible = false;

void dfs(int start, int stop, int level) {
  seens[start] = true;
  if (is_possible) {
    return;
  }
  for (int i = 0; i < graph[start].size(); i++) {
    pair<int, int> focused_station = graph[start][i];
    if (seens[focused_station.first]) {
      continue;
    }
    if (level >= focused_station.second) {
      if (focused_station.first == stop) {
        is_possible = true;
        return;
      }
      dfs(focused_station.first, stop, level);
    }
  }
}

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    graph[a].push_back(make_pair(b, c));
    graph[b].push_back(make_pair(a, c));
  }

  for (int i = 0; i < q; i++) {
    int l, s, t;
    cin >> l >> s >> t;
    s--;
    t--;
    // Init seen
    for (int i = 0; i < 3010; i++) {
      seens[i] = false;
    }
    is_possible = false;
    // Do DFS
    dfs(s, t, l);
    if (is_possible) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  return 0;
}

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<pair<int, int>> graph[200000];
vector<int> good_warehouse;
pair<int, int> good;
bool seen[200000];

int shortest_bfs(int start_point) {
  queue<int> adj;

  memset(seen, false, 200000);
  adj.push(start_point);
  seen[start_point] = true;
  int level_count = 0;

  while (!adj.empty()) {
    int focused_point = adj.front();
    adj.pop();
    for (int i = 0; i < graph[focused_point].size(); i++) {
      int loop_focused = graph[focused_point][i].first;
      int road_type = graph[focused_point][i].second;
      if (seen[loop_focused]) {
        continue;
      }
      seen[loop_focused] = true;
      bool is_possible = false;
      if (good.second != 1 || road_type == 1) {
        adj.push(loop_focused);
        is_possible = true;
      }

      if (loop_focused == good.first && is_possible) {
        level_count++;
        return level_count;
      }
    }

    level_count++;
    // cout << "End Level" << endl;
  }
  return -1;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    graph[a].push_back(make_pair(b, c));
    graph[b].push_back(make_pair(a, c));
  }

  for (int i = 0; i < k; i++) {
    int pos;
    cin >> pos;
    pos--;
    good_warehouse.push_back(pos);
  }

  int t, h;
  cin >> t >> h;
  t--;
  good = make_pair(t, h);

  // int max = -1;
  // for (int i = 0; i < good_warehouse.size(); i++) {
  //   int result = shortest_bfs(good_warehouse[i]);
  //   if (result != -1) {
  //     if (max == -1) {
  //       max = result;
  //     } else if (result < max) {
  //       max = result;
  //     }
  //   }
  // }
  // cout << max;
  cout << shortest_bfs(good_warehouse[0]);
  return 0;
}

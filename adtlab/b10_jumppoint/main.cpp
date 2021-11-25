#include <iostream>
#include <list>
#include <vector>

using namespace std;

vector<int> connected_point[1000];
vector<pair<int, int>> point;

bool seen[1000];
int layer[1000];
bool reach_end = false;

int n, r;

void print_pair(pair<int, int> pos) {
  cout << "(" << pos.first << "," << pos.second << ")";
}

int bfs(int s) {
  list<int> Q;

  Q.push_back(s);
  seen[s] = true;
  layer[s] = 0;

  while (!Q.empty()) {
    int u = Q.front();
    Q.pop_front();
    for (int d = 0; d < connected_point[u].size(); d++) {
      int v = connected_point[u][d];
      if (!seen[v]) {
        Q.push_back(v);
        seen[v] = true;
        layer[v] = layer[u] + 1;
        if (point[v].first == 100 && point[v].second == 100) {
          return layer[u] + 1;
        }
      }
    }
  }
  return -1;
}

int main() {
  cin >> n >> r;
  r *= r;
  pair<int, int> init_point = make_pair(0, 0);
  point.push_back(init_point);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    pair<int, int> pos = make_pair(x, y);
    point.push_back(pos);
  }
  pair<int, int> target_point = make_pair(100, 100);
  point.push_back(target_point);
  // Number of point should be n+2 now. (Start , End)
  for (int i = 0; i < n + 2; i++) {
    for (int j = 0; j < n + 2; j++) {
      if (i == j) {
        continue;
      }
      pair<int, int> pos_1 = point[i];
      pair<int, int> pos_2 = point[j];
      int del_x = pos_2.first - pos_1.first;
      int del_y = pos_2.second - pos_1.second;
      del_x *= del_x;
      del_y *= del_y;
      if (del_x + del_y <= r) {
        connected_point[i].push_back(j);
      }
    }
  }

  if (connected_point[0].size() == 0 || connected_point[n + 1].size() == 0) {
    cout << "-1" << endl;
  }

  // for (int i = 0; i < n + 2; i++) {
  //   vector<int> test = connected_point[i];
  //   print_pair(point[i]);
  //   cout << "--->";
  //   for (int j = 0; j < test.size(); j++) {
  //     print_pair(point[test[j]]);
  //     cout << " & ";
  //   }
  //   cout << endl;
  // }

  for (int i = 0; i < n + 2; i++) {
    seen[i] = false;
    layer[i] = -1;
  }
  int result = bfs(0);
  cout << result << endl;
  return 0;
}

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Pair < Connected Vertex, Min Speed Limit >
vector<pair<int, int>> graph[200000];

int n, m, s, q;

bool is_possible(int city_a, int city_b) {
  // Search by bfs
  queue<int> vertex;
  bool seen[200000];
  // Init seen
  for (int i = 0; i < m; i++) {
    seen[i] = false;
  }

  vertex.push(city_a);

  while (!vertex.empty()) {
    int focused_vertex = vertex.front();
    vertex.pop();
    if (seen[focused_vertex]) {
      continue;
    }
    seen[focused_vertex] = true;
    if (focused_vertex == city_b) {
      return true;
    }

    for (int i = 0; i < graph[focused_vertex].size(); i++) {
      pair<int, int> focused_road = graph[focused_vertex][i];
      if (seen[focused_road.first]) {
        continue;
      }
      if (focused_road.second <= s) {
        vertex.push(focused_road.first);
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> s >> q;
  for (int i = 0; i < m; i++) {
    int city_a, city_b, min_speed;
    cin >> city_a >> city_b >> min_speed;
    city_a--;
    city_b--;
    graph[city_a].push_back(make_pair(city_b, min_speed));
    graph[city_b].push_back(make_pair(city_a, min_speed));
  }

  for (int i = 0; i < q; i++) {
    int city_a, city_b;
    cin >> city_a >> city_b;
    city_a--;
    city_b--;
    if (is_possible(city_a, city_b)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }

  return 0;
}
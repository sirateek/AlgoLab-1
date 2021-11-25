#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

vector<int> adj[200010];
bool seen[200010];
// int levels[100010];
int color[200010];

int n, m;

bool bi_bfs(int s) {
  list<int> q;
  //   levels[s] = 0;
  q.push_back(s);
  seen[s] = true;

  while (!q.empty()) {
    int u = q.front();
    q.pop_front();

    // int l = levels[u];
    for (int d = 0; d < adj[u].size(); d++) {
      int v = adj[u][d];
      if (!seen[v]) {
        seen[v] = true;
        // levels[v] = l + 1;
        color[v] = 1 - color[u];
        q.push_back(v);
      }

      if (color[v] == color[u]) {
        return false;
      }
    }
  }
  return true;
}

void input_graph() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    adj[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // Init seen
  for (int i = 0; i < n; i++) {
    seen[i] = false;
  }

  bool result = bi_bfs(0);
  if (result) {
    cout << "yes" << endl;

  } else {
    cout << "no" << endl;
  }
}

int main() {
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    input_graph();
  }
  return 0;
}
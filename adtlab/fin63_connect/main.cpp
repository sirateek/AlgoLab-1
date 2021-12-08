#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

char words[1000][12];
vector<int> graph[1000];
bool seen[1000];

bool is_found = false;
int l, n, t;

void dfs(int start, int target) {
  seen[start] = true;
  if (is_found) {
    return;
  }
  for (int i = 0; i < graph[start].size(); i++) {
    if (!seen[graph[start][i]]) {
      if (graph[start][i] == target) {
        is_found = true;
        return;
      }
      dfs(graph[start][i], target);
    }
  }
}

int get_pos(string data_to_search) {
  for (int i = 0; i < n; i++) {
    string result = "";
    for (int j = 0; j < l; j++) {
      result += words[i][j];
    }
    if (result == data_to_search) {
      return i;
    }
  }
  return -1;
}

int main() {
  cin >> l >> n >> t;
  for (int i = 0; i < n; i++) {
    cin >> words[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }
      string result_a = "";
      for (int k = 1; k < l; k++) {
        result_a += words[i][k];
      }
      string result_b = "";
      for (int k = 0; k < l - 1; k++) {
        result_b += words[j][k];
      }
      //   cout << "A: " << result_a << " B: " << result_b << endl;
      if (result_a == result_b) {
        graph[i].push_back(j);
      }
    }
  }

  //   for (int i = 0; i < n; i++) {
  //     cout << i << ": ";
  //     for (int j = 0; j < graph[i].size(); j++) {
  //       cout << graph[i][j] << " ";
  //     }
  //     cout << endl;
  //   }

  // Test Case
  for (int i = 0; i < t; i++) {
    string word_1, word_2;
    cin >> word_1 >> word_2;
    int pos_1 = get_pos(word_1);
    // cout << "POS1: " << pos_1 << endl;
    int pos_2 = get_pos(word_2);
    // cout << "POS2: " << pos_2 << endl;
    is_found = false;
    memset(seen, false, 1000);
    dfs(pos_1, pos_2);
    if (is_found) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }

  return 0;
}

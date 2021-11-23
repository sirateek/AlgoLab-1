#include <iostream>
using namespace std;

char map_data[30][30];

bool seen[30][30];
int n, m;

bool is_found_star = false;
bool is_found_dollor = false;

int dfs(int a, int b) {
  if (seen[a][b]) {
    return 0;
  }
  if (a < 0 || a >= n || b < 0 || b >= m) {
    return 0;
  }
  // cout << "Goto " << a << "-" << b << endl;
  seen[a][b] = true;
  if (map_data[a][b] == '#') {
    // cout << "Found # at " << a << "-" << b << endl;
    return 0;
  }
  if (map_data[a][b] == '*') {
    is_found_star = true;
    // cout << "Found * at " << a << "-" << b << endl;
  } else if (map_data[a][b] == '$') {
    is_found_dollor = true;
    // cout << "Found $ at " << a << "-" << b << endl;
  }
  int sum = 1;
  sum += dfs(a, b + 1);
  sum += dfs(a + 1, b);
  sum += dfs(a - 1, b);
  sum += dfs(a, b - 1);
  return sum;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string input;
    cin >> input;
    for (int j = 0; j < m; j++) {
      map_data[i][j] = input[j];
    }
  }

  int super = 0;
  int medium = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!seen[i][j]) {
        // cout << "Start: " << i << "-" << j << endl;
        int count = dfs(i, j);
        if (is_found_star && is_found_dollor) {
          // cout << "Add Super" << count << endl;
          super += count;
        } else if (is_found_star || is_found_dollor) {
          // cout << "Add Medium" << count << endl;
          medium += count;
        }
        is_found_star = false;
        is_found_dollor = false;
        // cout << "Here" << count << " Super: " << super << " Medium" <<
        // endl;
      }
    }
  }
  int count = dfs(0, 5);
  cout << super << " " << medium;

  return 0;
}

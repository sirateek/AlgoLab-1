#include <fstream>
#include <iostream>

using namespace std;
// ofstream MyFile("output.txt");

char map_data[20][20];
bool seen[20][20];
int m, n;
char land;

void init_seen() {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      seen[i][j] = false;
    }
  }
}

int dfs(int a, int b) {
  if (b < 0) {
    b = n - 1;
  }
  if (b >= n) {
    b = 0;
  }
  if (seen[a][b]) {
    return 0;
  }
  //   cout << "Goto " << a << "-" << b << endl;
  seen[a][b] = true;
  if (map_data[a][b] != land) {
    // cout << "Not Found a land at " << a << "-" << b << endl;
    return 0;
  }
  //   cout << "Found a land at " << a << "-" << b << endl;
  int sum = 1;
  sum += dfs(a, b + 1);
  sum += dfs(a + 1, b);
  sum += dfs(a - 1, b);
  sum += dfs(a, b - 1);
  //   cout << "End search at " << a << "-" << b << endl;
  return sum;
}

int main() {

  while (cin >> m >> n) {
    for (int i = 0; i < m; i++) {
      string input;
      cin >> input;
      for (int j = 0; j < n; j++) {
        map_data[i][j] = input[j];
      }
    }
    int current_point_m, current_point_n;
    cin >> current_point_m >> current_point_n;
    land = map_data[current_point_m][current_point_n];
    // cout << land << endl;
    init_seen();
    dfs(current_point_m, current_point_n);
    int max = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int count = dfs(i, j);
        if (count > max) {
          max = count;
        }
      }
    }
    cout << max << endl;
  }
  //   MyFile.close();
  return 0;
}

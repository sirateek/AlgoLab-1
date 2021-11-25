#include <fstream>
#include <iostream>

using namespace std;

// ofstream MyFile("output.txt");

char map_data[100][100];
bool seen[100][100];
int n;

bool is_alive_chip = false;

void dfs(int a, int b) {
  if (map_data[a][b] == '.') {
    return;
  }
  if (a < 0 || a >= n || b < 0 || b >= n) {
    return;
  }

  if (seen[a][b]) {
    return;
  }
  seen[a][b] = true;

  if (map_data[a][b] == 'x') {
    is_alive_chip = true;
  }

  dfs(a, b + 1);
  dfs(a + 1, b);
  dfs(a - 1, b);
  dfs(a, b - 1);
}

void start_process(int case_num) {
  cin >> n;
  for (int i = 0; i < n; i++) {
    string input_data;
    cin >> input_data;
    for (int j = 0; j < n; j++) {
      map_data[i][j] = input_data[j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      seen[i][j] = false;
    }
  }
  int alive_count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (map_data[i][j] == '.') {
        continue;
      }
      dfs(i, j);
      //   cout << i << "-" << j << " is " << is_alive_chip << endl;
      if (is_alive_chip) {
        alive_count++;
      }
      is_alive_chip = false;
    }
  }
  cout << "Case " << case_num << ": " << alive_count << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i < t + 1; i++) {
    start_process(i);
  }
  //   MyFile.close();
  return 0;
}

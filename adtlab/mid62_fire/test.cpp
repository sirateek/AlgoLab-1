#include <iostream>
#include <queue>
using namespace std;

bool area[10000][10000];

int main() {
  int n, k, r, c, time = 0;
  cin >> n >> k;
  queue<int> fire_x;
  queue<int> fire_y;
  queue<int> temp_x;
  queue<int> temp_y;
  bool has_burn = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      area[i][j] = false;
    }
  }
  for (int i = 0; i < k; i++) {
    cin >> r >> c;
    fire_x.push(r - 1);
    fire_y.push(c - 1);
    area[r - 1][c - 1] = true;
  }
  while (!fire_x.empty()) {
    while (!fire_x.empty()) {
      temp_x.push(fire_x.front());
      temp_y.push(fire_y.front());
      fire_x.pop();
      fire_y.pop();
    }
    while (!temp_x.empty()) {
      int x = temp_x.front(), y = temp_y.front();

      if (x == 0) {
        if (!area[1][y]) {
          area[1][y] = true;
          fire_x.push(1);
          fire_y.push(y);
        }
      } else if (x == n - 1) {
        if (!area[n - 2][y]) {
          area[n - 2][y] = true;
          fire_x.push(n - 2);
          fire_y.push(y);
        }
      } else {
        if (!area[x - 1][y]) {
          area[x - 1][y] = true;
          fire_x.push(x - 1);
          fire_y.push(y);
        }
        if (!area[x + 1][y]) {
          area[x + 1][y] = true;
          fire_x.push(x + 1);
          fire_y.push(y);
        }
      }

      if (y == 0) {
        if (!area[x][1]) {
          area[x][1] = true;
          fire_x.push(x);
          fire_y.push(1);
        }
      } else if (y == n - 1) {
        if (!area[x][n - 2]) {
          area[x][n - 2] = true;
          fire_x.push(x);
          fire_y.push(n - 2);
        }
      } else {
        if (!area[x][y - 1]) {
          area[x][y - 1] = true;
          fire_x.push(x);
          fire_y.push(y - 1);
        }
        if (!area[x][y + 1]) {
          area[x][y + 1] = true;
          fire_x.push(x);
          fire_y.push(y + 1);
        }
      }

      temp_x.pop();
      temp_y.pop();
    }
    time++;
  }
  cout << time - 1;
}
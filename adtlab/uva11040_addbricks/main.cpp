#include <iostream>

using namespace std;

void findSolution() {
  int bricks[9][9];
  for (int i = 0; i < 9; i += 2) {
    for (int j = 0; j < i + 1; j += 2) {
      cin >> bricks[i][j];
    }
  }
  for (int j = 1; j < 9; j += 2) {
    bricks[8][j] = (bricks[6][j - 1] - bricks[8][j - 1] - bricks[8][j + 1]) / 2;
  }

  for (int i = 7; i > 0; i--) {
    for (int j = i % 2 != 0 ? 0 : 1; j < i + 1; j++) {
      bricks[i][j] = bricks[i + 1][j] + bricks[i + 1][j + 1];
    }
  }

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < i + 1; j++) {
      if (j == i) {
        cout << bricks[i][j] << endl;
      } else {
        cout << bricks[i][j] << " ";
      }
    }
  }
}

int main() {

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    findSolution();
  }

  return 0;
}

#include <iostream>
#include <queue>
using namespace std;
bool board[10000][10000];

struct Coord {
  int row;
  int column;
  Coord(int row, int column) : row(row), column(column) {}
};

int main() {
  int n, k;
  cin >> n >> k;
  queue<Coord> fireCoord;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      board[i][j] = false;
    }
  }

  for (int i = 0; i < k; i++) {
    int row, column;
    cin >> row >> column;
    Coord *newFire = new Coord(row - 1, column - 1);
    fireCoord.push(*newFire);
    board[row - 1][column - 1] = true;
  }
  int sec = 0;
  while (true) {
    int size = fireCoord.size();
    for (int i = 0; i < size; i++) {
      Coord focusedFire = fireCoord.front();
      int row = focusedFire.row;
      int column = focusedFire.column;
      if (row + 1 < n && !board[row + 1][column]) {
        Coord newCoord = Coord(row + 1, column);
        board[row + 1][column] = true;
        fireCoord.push(newCoord);
      }
      if (row - 1 >= 0 && !board[row - 1][column]) {
        board[row - 1][column] = true;
        Coord newCoord = Coord(row - 1, column);
        fireCoord.push(newCoord);
      }
      if (column + 1 < n && !board[row][column + 1]) {
        board[row][column + 1] = true;
        Coord newCoord = Coord(row, column + 1);
        fireCoord.push(newCoord);
      }
      if (column - 1 >= 0 && !board[row][column - 1]) {
        board[row][column - 1] = true;
        Coord newCoord = Coord(row, column - 1);
        fireCoord.push(newCoord);
      }
      fireCoord.pop();
    }
    if (fireCoord.size() == 0) {
      break;
    }
    sec++;
  }
  cout << sec << endl;
  return 0;
}

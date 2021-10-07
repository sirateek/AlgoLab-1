#include <iostream>

using namespace std;

struct Node {
  int value;
  Node *next;
  Node(int value, Node *next = nullptr) : value(value), next(next){};
};

void rotateColumn(int slot[][4], int col) {
  int valueRow4 = slot[3][col];
  for (int i = 3; i > 0; i--) {
    slot[i][col] = slot[i - 1][col];
  }
  slot[0][col] = valueRow4;
}

void printColumn(int slot[][4]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cout << slot[i][j] << " ";
    }
    cout << endl;
  }
}

int findScore(int slot[][4]) {
  int sum = 0;
  for (int i = 0; i < 4; i++) {
    if (slot[i][0] == slot[i][1] && slot[i][0] == slot[i][2] &&
        slot[i][0] == slot[i][3]) {
      sum++;
    }
  }
  return sum;
}
int main() {
  int maxScore = 0;
  int slot[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      int value;
      cin >> value;
      slot[i][j] = value;
    }
  }

  for (int i = 0; i < 4; i++) {
    rotateColumn(slot, 0);
    for (int j = 0; j < 4; j++) {
      rotateColumn(slot, 1);
      for (int k = 0; k < 4; k++) {
        rotateColumn(slot, 2);
        for (int x = 0; x < 4; x++) {
          rotateColumn(slot, 3);
          int score = findScore(slot);
          if (score > maxScore) {
            maxScore = score;
          }
        }
      }
    }
  }
  cout << maxScore << endl;
  return 0;
}

#include <iostream>

using namespace std;

struct Ball {
  int id;
  int color;
  Ball *next;
  Ball(int id, int color = 0, Ball *next = 0)
      : id(id), color(color), next(next) {}
};

void printList(Ball *dummyBall) {
  dummyBall = dummyBall->next;
  while (dummyBall != nullptr) {
    cout << dummyBall->id << endl;
    dummyBall = dummyBall->next;
  }
}

void addLastBall(Ball *&lastBall, int *count, int color) {
  *count = *count + 1;
  Ball *newBall = new Ball(*count, color);
  lastBall->next = newBall;
  lastBall = newBall;
}

void addBall(Ball *dummyBall, int *count, int pos, int color) {
  *count = *count + 1;
  while (dummyBall != nullptr) {
    if (dummyBall->id == pos) {
      break;
    }
    dummyBall = dummyBall->next;
  }
  dummyBall->next = new Ball(*count, color, dummyBall->next);
}

int main() {
  Ball *dummyBall = new Ball(0);
  Ball *lastBall = dummyBall;
  int count = 0;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int color;
    cin >> color;
    addLastBall(lastBall, &count, color);
  }

  for (int i = 0; i < m; i++) {
    int color, position;
    cin >> color >> position;
    addBall(dummyBall, &count, position, color);
  }

  printList(dummyBall);
  return 0;
}

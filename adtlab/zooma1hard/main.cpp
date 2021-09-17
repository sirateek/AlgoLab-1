#include <iostream>

using namespace std;

struct Ball {
  int id;
  Ball *next;
  Ball(int id = -1, Ball *next = 0) : id(id), next(next) {}
};

void printList(Ball *dummyBall) {
  dummyBall = dummyBall->next;
  while (dummyBall != nullptr) {
    cout << dummyBall->id << endl;
    dummyBall = dummyBall->next;
  }
}

// void printArray(Ball **ballList, int count) {
//   for (int i = 0; i < count; i++) {
//     Ball *focusedBall = ballList[i];
//     cout << focusedBall->id << endl;
//   }
// }

void addToLast(Ball **ballList, Ball *&lastBall, int *count) {
  Ball *newBall = new Ball(*count + 1);
  ballList[*count] = newBall;
  lastBall->next = newBall;
  lastBall = newBall;
  *count = *count + 1;
}

void addToArray(Ball **ballList, int *count, int pos) {
  Ball *focusedBall = ballList[pos];
  Ball *newBall = new Ball(*count + 1, focusedBall->next);
  focusedBall->next = newBall;
  ballList[*count] = newBall;
  *count = *count + 1;
}

int main() {
  int n, m;
  cin >> n >> m;

  Ball *dummyBall = new Ball();
  Ball *lastBall = dummyBall;
  Ball *balls[1000000];
  int count = 0;

  for (int i = 0; i < n; i++) {
    int color;
    cin >> color;
    addToLast(balls, lastBall, &count);
  }

  for (int i = 0; i < m; i++) {
    int color, pos;
    cin >> color >> pos;
    addToArray(balls, &count, pos - 1);
  }
  printList(dummyBall);
  return 0;
}

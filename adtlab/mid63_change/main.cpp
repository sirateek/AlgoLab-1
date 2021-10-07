#include <iostream>

using namespace std;

struct Box {
  int green;
  int black;
  int sum;
  Box(int green, int black) : green(green), black(black) {
    sum = green - black;
  }
};

void sortBox(Box *boxes[], int n) {
  // Use Bubble Sort
  while (true) {
    bool changed = false;
    for (int i = 0; i < n - 1; i++) {
      if (boxes[i]->sum > boxes[i + 1]->sum) {
        Box *cacheBox = boxes[i];
        boxes[i] = boxes[i + 1];
        boxes[i + 1] = cacheBox;
        changed = true;
      }
    }
    if (!changed) {
      break;
    }
  }
}

void implementK(Box *boxes[], int n, int k) {

  int sumMost = 0;
  for (int i = 0; i <= k; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += boxes[j]->sum;
    }
    if (sum > sumMost || i == 0) {
      sumMost = sum;
    }
  }
  cout << sumMost << endl;
}

int main() {
  int n, k;
  cin >> n >> k;
  Box *boxes[1000];
  for (int i = 0; i < n; i++) {
    int green, black;
    cin >> green >> black;
    Box *newBox = new Box(green, black);
    boxes[i] = newBox;
  }

  sortBox(boxes, n);
  implementK(boxes, n, k);

  return 0;
}

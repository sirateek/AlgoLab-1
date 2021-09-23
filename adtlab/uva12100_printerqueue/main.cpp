#include <iostream>

using namespace std;

struct PrintQue {
  int piority;
  int id;
  bool isFocused;

  PrintQue(int piority = 0, int id = 0, bool isFocused = false)
      : piority(piority), id(id), isFocused(isFocused) {}
};

PrintQue removeItem(PrintQue *piority, int pos, int *n) {
  *n = *n - 1;
  PrintQue que = piority[pos];
  for (int i = pos; i < *n; i++) {
    piority[i] = piority[i + 1];
  }
  return que;
}

void moveToLast(PrintQue *piority, int pos, int n) {
  PrintQue que = piority[pos];
  removeItem(piority, pos, &n);
  piority[n] = que;
}

int calTime(PrintQue *piority, int myPos, int n) {
  int count = 0;
  while (n != 0) {
    PrintQue que = piority[0];
    int maxPos = 0;
    int maxValue = piority[0].piority;
    for (int j = 1; j < n; j++) {
      if (piority[j].piority > maxValue) {
        maxPos = j;
        maxValue = piority[j].piority;
      }
    }
    if (maxPos != 0) {
      moveToLast(piority, 0, n);
    } else {
      PrintQue removedQue = removeItem(piority, 0, &n);
      count++;
      if (removedQue.isFocused) {
        break;
      }
    }
  }
  return count;
}

int main() {
  int num;
  cin >> num;
  int result[num];
  for (int i = 0; i < num; i++) {
    int n, m;
    cin >> n >> m;
    PrintQue piority[n];
    for (int j = 0; j < n; j++) {
      int piorityNum;
      cin >> piorityNum;
      PrintQue *que;
      if (j == m) {
        que = new PrintQue(piorityNum, j, true);
      } else {
        que = new PrintQue(piorityNum, j);
      }
      piority[j] = *que;
    }
    result[i] = calTime(piority, m, n);
  }
  for (int i = 0; i < num; i++) {
    cout << result[i] << endl;
  }
  return 0;
}

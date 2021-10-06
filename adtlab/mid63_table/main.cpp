#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int table[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> table[i][j];
    }
  }
  int sumRow[n];
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
      sum += table[i][j];
    }
    sumRow[i] = sum;
  }

  int sumColumn[n];
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
      sum += table[j][i];
    }
    sumColumn[i] = sum;
  }

  int focusedSum = 0;
  if (sumRow[0] == sumRow[1]) {
    focusedSum = sumRow[0];
  } else {
    focusedSum = sumRow[2];
  }

  for (int i = 0; i < n; i++) {
    if (sumRow[i] != focusedSum) {
      int j;
      for (j = 0; j < n; j++) {
        if (sumColumn[j] != focusedSum) {
          break;
        }
      }
      cout << table[i][j] << endl;
      break;
    }
  }

  return 0;
}

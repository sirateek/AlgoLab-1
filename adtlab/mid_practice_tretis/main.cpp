#include <iostream>

using namespace std;

int find_max(int array_to_find[], int start, int stop) {
  int max = array_to_find[start];
  for (int i = start; i < stop; i++) {
    if (array_to_find[i] > max) {
      max = array_to_find[i];
    }
  }
  return max;
}

int main() {
  int n;
  cin >> n;
  int column_height[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for (int i = 0; i < n; i++) {
    char t;
    int c;
    cin >> t >> c;
    if (t == '-') {
      int max_height = find_max(column_height, c - 1, c + 3);
      max_height++;
      for (int j = c - 1; j < c + 3; j++) {
        column_height[j] = max_height;
      }
    } else if (t == 'i') {
      column_height[c - 1] += 4;
    } else if (t == 'o') {
      int max_height = find_max(column_height, c - 1, c + 1);
      max_height += 2;
      for (int j = c - 1; j < c + 1; j++) {
        column_height[j] = max_height;
      }
    }
  }

  cout << find_max(column_height, 0, 10);
  return 0;
}

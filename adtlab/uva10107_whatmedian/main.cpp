#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int num[10000];
  int result[10000];
  int x = 0;
  while (cin >> num[x]) {
    x++;
    sort(num, num + x);
    if (x % 2 == 0) {
      int pos = x / 2;
      int first = num[pos];
      int second = num[pos - 1];
      result[x - 1] = floor((first + second) / 2);
    } else {
      int pos = ((x - 1) / 2);
      result[x - 1] = num[pos];
    }
  }

  for (int i = 0; i < x; i++) {
    cout << result[i] << endl;
  }

  return 0;
}

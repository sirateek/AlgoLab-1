#include <iostream>

using namespace std;

int main() {
  int n = 0;
  int exps[1000];

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> exps[i];
  }

  int totals = 0;
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (count == 3) {
      totals += exps[i] * 2;
      count = 0;
      continue;
    }
    totals += exps[i];
    count++;
  }
  cout << totals;
  return 0;
}

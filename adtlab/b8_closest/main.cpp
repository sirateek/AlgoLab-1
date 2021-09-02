#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
  int num_list[100000];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num_list[i];
  }

  sort(num_list, num_list + n);

  int min_diff = abs(num_list[0] - num_list[1]);
  for (int i = 0; i < n - 1; i++) {
    int value = abs(num_list[i] - num_list[i + 1]);
    if (value < min_diff) {
      min_diff = value;
    }
  }
  cout << min_diff;
  return 0;
}

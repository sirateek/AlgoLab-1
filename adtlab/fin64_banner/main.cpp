#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> data_vec;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;
    data_vec.push_back(make_pair(h, i));
  }
  sort(data_vec.begin(), data_vec.end());
  int max = -1;
  for (int i = 0; i < n - 1; i++) {
    pair<int, int> current = data_vec[i];
    pair<int, int> next = data_vec[i + 1];
    if (current.first != next.first) {
      continue;
    }
    int result = abs(current.second - next.second);
    if (result > max) {
      max = result;
    }
  }
  cout << max;
  return 0;
}

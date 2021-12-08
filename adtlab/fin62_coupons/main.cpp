#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, w;
  cin >> n >> w;
  vector<pair<int, int>> data;

  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
    data.push_back(make_pair(value, i));
  }

  sort(data.begin(), data.end());

  int give_out[n];

  for (int i = n - 1; i >= 0; i--) {
    int value = data[i].first;
    int pos = data[i].second;
    if (value > w) {
      give_out[pos] = 0;
      continue;
    }
    int give_count = w / value;
    if (give_count != 0) {
      w -= value * give_count;
    }
    give_out[pos] = give_count;
  }

  for (int i = 0; i < n; i++) {
    cout << give_out[i] << " ";
  }

  return 0;
}

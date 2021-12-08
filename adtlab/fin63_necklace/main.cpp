#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> data;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    data.push_back(make_pair(b, a));
  }

  sort(data.begin(), data.end());
  int current_give = data[0].first;
  int count = 1;
  for (int i = 1; i < data.size(); i++) {
    pair<int, int> focused = data[i];
    if (focused.second > current_give) {
      count++;
      current_give = focused.first;
    }
  }
  cout << count;
  return 0;
}

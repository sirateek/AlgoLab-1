#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> data;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    data.push_back(x);
  }
  sort(data.begin(), data.end());
  int ans = 0;
  int cache_count = 0;
  int current_focus = -99999;
  for (int i = 0; i < n; i++) {
    if (current_focus != data[i] || i == n - 1) {
      current_focus = data[i];
      if (cache_count >= 3) {
        ans++;
      }
      cache_count = 1;
      continue;
    }
    cache_count++;
  }
  cout << ans;
  return 0;
}

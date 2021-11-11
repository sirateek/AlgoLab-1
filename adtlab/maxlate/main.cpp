#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  vector<pair<int, int>> works;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int d, c;
    cin >> d >> c;
    pair<int, int> cache = make_pair(d, c);
    works.push_back(cache);
  }
  sort(works.begin(), works.end());

  int max_late_day = 0;
  int current_day = 0;
  for (int i = 0; i < n; i++) {
    int required_work_day = works[i].second;
    int deadline = works[i].first;
    current_day += required_work_day;
    if (current_day > deadline + 10) {
      int late_day = current_day - deadline - 10;
      if (late_day > max_late_day) {
        max_late_day = late_day;
      }
    }
  }
  cout << max_late_day * 1000 << endl;
  return 0;
}

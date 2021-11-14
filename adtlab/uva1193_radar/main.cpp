#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int count_case = 0;
  while (true) {
    count_case++;
    int n, d;
    cin >> n >> d;
    if (n == 0 && d == 0) {
      break;
    }
    vector<pair<double, double>> ranges;
    bool is_possible = true;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      double sqrt_d = sqrt(d * d - y * y);
      if (y > d) {
        is_possible = false;
      }
      pair<double, double> range = make_pair(x - sqrt_d, x + sqrt_d);
      ranges.push_back(range);
    }
    if (!is_possible) {
      cout << "Case " << count_case << ": "
           << "-1" << endl;
      continue;
    }
    sort(ranges.begin(), ranges.end());
    int i;
    int count = 0;
    for (i = 0; i < n;) {
      int j;
      for (j = i; j < n;) {
        if (ranges[j].first > ranges[i].second) {
          break;
        }
        if (ranges[i].second > ranges[j].second) {
          count--;
          break;
        }
        j++;
      }
      i = j;
      count++;
    }
    cout << "Case " << count_case << ": " << count << endl;
  }
  return 0;
}

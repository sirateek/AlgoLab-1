#include <iostream>
#include <set>

using namespace std;

int main() {
  int n, m;
  set<int> x;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int xi;
    cin >> xi;
    x.insert(xi);
  }

  for (int i = 0; i < m; i++) {
    int yi;
    cin >> yi;
    int upper = *x.upper_bound(yi);
    int lower = *x.lower_bound(yi);
    auto upper_iter = x.upper_bound(yi);
    upper_iter--;
    upper = *upper_iter;

    int cal_upper = abs(upper - yi);
    int cal_lower = abs(lower - yi);
    if (cal_upper > cal_lower) {
      cout << lower << endl;
    } else {
      cout << upper << endl;
    }
  }
  return 0;
}

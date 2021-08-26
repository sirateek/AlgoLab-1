#include <iostream>

using namespace std;

int main() {
  int n = 0;
  int ants_per_day[1000];

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ants_per_day[i];
  }

  int totals = 0;
  for (int i = 0; i < n; i++) {
    totals += ants_per_day[i] > 1000 ? 1000 : ants_per_day[i];
    if (ants_per_day[i] >= 1000) {
      i++;
    }
  }
  cout << totals;
  return 0;
}

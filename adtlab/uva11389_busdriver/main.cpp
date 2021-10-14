#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void input(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
}

int main() {
  while (true) {
    int n, d, r;
    cin >> n >> d >> r;
    vector<pair<int, int>> driver;
    int morning[100];
    int evening[100];
    if (n == 0 && d == 0 && r == 0) {
      break;
    }
    input(morning, n);
    input(evening, n);
    for (int i = 0; i < n; i++) {
      driver.push_back(make_pair(morning[i], i));
    }
    sort(driver.begin(), driver.end());
    sort(evening, evening + n);
    int pay = 0;
    for (int i = 0; i < n; i++) {
      if (driver[i].first + evening[n - i - 1] > d) {
        pay += driver[i].first + evening[n - i - 1] - d;
      }
    }
    cout << pay * r << endl;
  }
  return 0;
}

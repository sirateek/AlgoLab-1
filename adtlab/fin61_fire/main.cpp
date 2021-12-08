#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, r;
  cin >> n >> r;
  vector<int> garage_pos;
  for (int i = 0; i < n; i++) {
    int pos;
    cin >> pos;
    garage_pos.push_back(pos);
  }
  sort(garage_pos.begin(), garage_pos.end());
  int current_fire_pos = garage_pos[0] + r;
  int count_fire = 1;
  for (int i = 1; i < garage_pos.size(); i++) {
    int garage = garage_pos[i];
    if (current_fire_pos + r < garage) {
      count_fire++;
      current_fire_pos = garage + r;
    }
  }
  cout << count_fire;
  return 0;
}

#include <iostream>

using namespace std;

int find_lowest_water(int buckets[]) {
  int lowest_pos = 0;
  for (int i = 1; i < 5; i++) {
    if (buckets[i] < buckets[lowest_pos]) {
      lowest_pos = i;
    }
  }
  return lowest_pos;
}

int main() {
  int buckets[5] = {0, 0, 0, 0, 0};
  int n;
  int jars[1000];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> jars[i];
  }
  cout << endl;
  int water_tank = 0;
  for (int i = 0; i < n; i++) {
    int lowest_pos = find_lowest_water(buckets);
    buckets[lowest_pos] += jars[i];
    if (buckets[lowest_pos] >= 1000) {
      buckets[lowest_pos] = 0;
      water_tank++;
    }
  }
  cout << water_tank * 1000 << endl;
  return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  vector<int> result;
  for (int i = 1; i <= t; i++) {

    int n, p, q;
    cin >> n >> p >> q;
    int weight[30];
    for (int i = 0; i < n; i++) {
      cin >> weight[i];
    }
    sort(weight, weight + n);
    int count = 0;
    int totalWeight = 0;
    for (int i = 0; i < n; i++) {
      if (totalWeight + weight[i] > q || i >= p) {
        break;
      }
      count++;
      totalWeight += weight[i];
    }
    result.push_back(count);
  }

  int size = result.size();
  for (int i = 0; i < size; i++) {
    cout << "Case " << i + 1 << ": " << result[i] << endl;
  }
  return 0;
}

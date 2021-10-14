#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int max_n = 100000;

int s[max_n];
int t[max_n];

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> workIndex;

  for (int i = 0; i < n; i++) {
    cin >> s[i] >> t[i];
  }

  for (int i = 0; i < n; i++) {
    workIndex.push_back(make_pair(t[i], i));
  }

  sort(workIndex.begin(), workIndex.end());
  int lastStop = -1;
  int count = 0;
  for (int i = 0; i < n; ++i) {
    int j = workIndex[i].second;
    if (s[j] >= lastStop) {
      count++;
      lastStop = workIndex[i].first;
    }
  }
  cout << count << endl;
}

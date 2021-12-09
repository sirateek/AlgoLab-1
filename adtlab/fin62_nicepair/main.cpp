#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> papers;

int main() {
  int n, l;
  cin >> n >> l;
  int count = 0;
  for (int i = 0; i < n; i++) {
    int w, c;
    cin >> w >> c;
    for (int j = 0; j < i; j++) {
      int weight_j = papers[j].first;
      int color_j = papers[j].second;
      if (w + weight_j == l && c != color_j) {
        count++;
      }
    }
    papers.push_back(make_pair(w, c));
  }
  cout << count;

  return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int find_max_freq(vector<int> data) {
  sort(data.begin(), data.end());
  int max = data[0];
  int max_count = 1;
  int focused = data[0];
  int focused_count = 1;
  for (int i = 1; i < data.size(); i++) {
    // cout << "Checking for: " << data[i] << " ; Focused: " << focused
    //      << " ; Focused Count: " << focused_count << endl;
    // cout << " - Max: " << max << " ; Max Count " << max_count << endl;
    if (data[i] != focused) {
      //   cout << "Changed Focused" << endl;
      if (focused_count > max_count) {
        // cout << "Focused has more count" << endl;
        max = data[i - 1];
        max_count = focused_count;
      }
      focused = data[i];
      focused_count = 1;
      continue;
    }
    focused_count++;
  }
  return max;
}

int main() {
  int n;
  cin >> n;
  vector<int> seq;

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    seq.push_back(num);
  }

  vector<int> result;

  for (int i = 0; i < n - 1; i++) {
    int i2 = i + 1;
    result.push_back(abs(seq[i] - seq[i2]));
  }
  for (int i = 0; i < n - 2; i++) {
    int i2 = i + 2;
    result.push_back(abs(seq[i] - seq[i2]));
  }

  //   for (int i = 0; i < result.size(); i++) {
  //     cout << result[i] << " ";
  //   }
  cout << find_max_freq(result);
  return 0;
}

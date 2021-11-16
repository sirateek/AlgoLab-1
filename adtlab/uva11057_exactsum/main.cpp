#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int n;
  int num[1000000];
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> num[i];
    }
    int target;
    cin >> target;
    sort(num, num + n);
    int start = 0;
    int end = n - 1;
    int low_a = -1;
    int low_b = -1;

    while (start < end) {
      if (num[start] + num[end] == target) {
        low_a = num[start];
        low_b = num[end];
        end--;
        start++;
      } else if (num[start] + num[end] > target) {
        end--;
      } else {
        start++;
      }
    }

    cout << "Peter should buy books whose prices are " << low_a << " and "
         << low_b << "." << endl;
    cout << endl;
  }
  return 0;
}

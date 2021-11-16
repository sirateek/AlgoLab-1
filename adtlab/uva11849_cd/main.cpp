#include <algorithm>
#include <iostream>

using namespace std;

bool search(int *jack_array, int begin, int end, int target) {
  if (end - begin < 1) {
    return false;
  }

  int mid = (begin + end) / 2;
  if (jack_array[mid] == target) {
    return true;
  } else if (target < jack_array[mid]) {
    return search(jack_array, begin, mid, target);
  } else {
    return search(jack_array, mid + 1, end, target);
  }
}

int main() {
  int jack_have[1000000];
  while (true) {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0)
      break;
    for (int i = 0; i < n; i++) {
      cin >> jack_have[i];
    }
    sort(jack_have, jack_have + n);
    int count = 0;
    for (int i = 0; i < m; i++) {
      int target;
      cin >> target;
      if (search(jack_have, 0, n, target)) {
        count++;
      }
    }
    cout << count << endl;
  }
  return 0;
}

#include <iostream>

using namespace std;

int flip_sort_count(int list[], int n) {
  int flip_count = 0;
  while (true) {
    bool changed = false;
    for (int i = 0; i < n - 1; i++) {
      if (list[i] > list[i + 1]) {
        int cache = list[i];
        list[i] = list[i + 1];
        list[i + 1] = cache;
        flip_count++;
        changed = true;
      }
    }
    if (!changed) {
      break;
    }
  }
  return flip_count;
}

int main() {
  int result[1000];
  int num_result = 0;
  int n = 0;
  while (cin >> n) {
    int cache_list[1000];
    for (int i = 0; i < n; i++) {
      cin >> cache_list[i];
    }
    result[num_result] = flip_sort_count(cache_list, n);
    num_result++;
  }

  for (int i = 0; i < num_result; i++) {
    cout << "Minimum exchange operations : " << result[i] << endl;
  }

  return 0;
}

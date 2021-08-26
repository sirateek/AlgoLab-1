#include <iostream>
using namespace std;

void find_max_min(int b[], int n, int *pointer_max, int *pointer_min) {
  *pointer_max = 0;
  *pointer_min = 0;

  for (int i = 0; i < n; i++) {
    if (b[i] > *pointer_max) {
      *pointer_max = b[i];
    }
  }
  *pointer_min = *pointer_max;
  for (int i = 0; i < n; i++) {
    if (b[i] < *pointer_min) {
      *pointer_min = b[i];
    }
  }
}

int main() {
  int a[1000];
  int n;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int mx, mn;
  find_max_min(a, n, &mx, &mn);

  cout << "max = " << mx << endl;
  cout << "min = " << mn << endl;
}
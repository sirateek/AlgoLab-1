#include <iostream>

using namespace std;

int get_last(int n, int k) {

  if (n == 1) {
    return 0;
  }
  return (get_last(n - 1, k) + k) % n;
}

int main() {
  int n;
  int k;
  cin >> n >> k;

  cout << get_last(n, k) + 1;
  return 0;
}

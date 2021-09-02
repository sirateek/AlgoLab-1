#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int num_list[100000];
  int n;
  int k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> num_list[i];
  }

  sort(num_list, num_list + n);

  int number_to_print = floor(n / k);
  for (int i = 1; i < number_to_print + 1; i++) {
    cout << num_list[k * i - 1] << endl;
  }
  return 0;
}

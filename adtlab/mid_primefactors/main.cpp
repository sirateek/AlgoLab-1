#include <iostream>

using namespace std;

bool is_prime(int number) {
  for (int i = 2; i < number; i++) {
    if (number % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  int prime_count = 0;

  cin >> n;
  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      if (is_prime(i)) {
        prime_count++;
      }
    }
  }
  cout << prime_count;
  return 0;
}

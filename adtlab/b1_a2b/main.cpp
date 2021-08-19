#include <iostream>

using namespace std;

int main() {
  int a,b;
  int sum = 0;
  cin >> a >> b;
    do {
        sum += a;
        a++;
    } while(a != b + 1);
    cout << sum;
  return 0;
}

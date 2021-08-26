#include <iostream>
using namespace std;

void dosomething(int **a) { *a = new int[100]; }

int main() {
  int *x = 0;
  cout << x << endl;
  dosomething(&x);
  cout << "Helo1" << endl;
  for (int i = 0; i < 100; i++) {
    x[i] = i * 2;
  }
  cout << x[1] + x[20] + x[99] << endl;

  delete[] x;
}
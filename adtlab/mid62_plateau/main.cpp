#include <iostream>

using namespace std;

int main() {
  int n, p, s;
  cin >> n;
  p = 0;
  s = 0;
  int previousCheck = 0;
  int stackArea = 0;
  bool pCheck = false;
  bool sCheck = false;
  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
    if (i != 0) {
      if (value == previousCheck) {
        // cout << "Add Stack: " << stackArea << "+1" << endl;
        stackArea++;
        continue;
      }
      if (value < previousCheck && pCheck) {
        // cout << "Add P: " << stackArea << " At " << i << endl;
        p += stackArea;
        stackArea = 0;
        pCheck = false;
      } else if (value > previousCheck && sCheck) {
        // cout << "Add S: " << stackArea << " At " << i << endl;
        s += stackArea;
        stackArea = 0;
        sCheck = false;
      }
      if (value > previousCheck && pCheck) {
        stackArea = 0;
        pCheck = false;
      } else if (value < previousCheck && sCheck) {
        stackArea = 0;
        sCheck = false;
      }

      if (value > previousCheck && !pCheck) {
        // cout << "Stack P: " << i << endl;
        pCheck = true;
        stackArea = 1;
      } else if (value < previousCheck && !sCheck) {
        // cout << "Stack S: " << i << endl;
        sCheck = true;
        stackArea = 1;
      }
    }
    previousCheck = value;
  }

  cout << p << " " << s << endl;
  return 0;
}

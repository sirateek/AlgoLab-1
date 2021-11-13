#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t, count_case;
  count_case = 1;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    vector<bool> processed;
    string input_string;
    cin >> n;
    cin >> input_string;
    int count = 0;
    for (int j = 0; j < n; j++) {
      if (input_string[j] == '.') {
        count++;
        j += 2;
      }
    }
    cout << "Case " << count_case << ": " << count << endl;
    ;
    count_case++;
  }
  return 0;
}

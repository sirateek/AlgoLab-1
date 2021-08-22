#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int numbers[1000];
    int input;
    cin >> input;
    for (int i=0; i<input; i++) {
        cin >> numbers[i];
    }

    for (int i=0; i<input; i++){
        int result = 315 * numbers[i] + 36962;
        cout << abs((result / 10) % 10) << "\n";
    }
  return 0;
}

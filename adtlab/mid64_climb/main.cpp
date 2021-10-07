#include <iostream>
using namespace std;

int main() {
  int n, stackEnergy, totalEnergy;
  cin >> n;
  stackEnergy = 0;
  totalEnergy = 0;
  int previousHeight = 0;
  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;

    if (value > previousHeight) {
      // Add energy
      totalEnergy += value - previousHeight;
      totalEnergy += stackEnergy;
      stackEnergy++;
    } else {
      stackEnergy = 0;
    }
    // Set previous height
    previousHeight = value;
  }

  cout << totalEnergy << endl;
  return 0;
}

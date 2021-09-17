#include <cstring>
#include <iostream>

using namespace std;

void groupReverse(string text, int groupNum) {
  string result = "";
  string cacheResult = "";
  int count = 0;
  int groupSize = text.length() / groupNum;
  for (int i = 0; i < text.length(); i++) {
    cacheResult = text[i] + cacheResult;
    count++;
    if (count == groupSize) {
      result += cacheResult;
      cacheResult = "";
      count = 0;
    }
  }
  cout << result << endl;
}

int main() {
  int c;
  do {
    string text;
    cin >> c;
    if (c == 0) {
      break;
    }
    cin >> text;
    groupReverse(text, c);
  } while (true);
  return 0;
}

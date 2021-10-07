#include <iostream>
#include <stack>

using namespace std;

int main() {
  stack<int> ballPipe;
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
    if (ballPipe.size() == 0) {
      ballPipe.push(value);
      continue;
    }
    if (k == 2) {
      if (ballPipe.top() == value) {
        ballPipe.pop();
      } else {
        ballPipe.push(value);
      }
    } else if (k == 3) {
      if (ballPipe.size() < 2) {
        ballPipe.push(value);
        continue;
      }
      int cache1 = ballPipe.top();
      ballPipe.pop();
      int cache2 = ballPipe.top();
      ballPipe.pop();
      if (value != cache1 || value != cache2) {
        ballPipe.push(cache2);
        ballPipe.push(cache1);
        ballPipe.push(value);
      }
    }
  }
  cout << ballPipe.size() << endl;
  return 0;
}

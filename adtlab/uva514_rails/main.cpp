#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool isInQueue(int targetNumber, queue<int> queue) {
  int size = queue.size();
  for (int i = 0; i < size; i++) {
    if (queue.front() == targetNumber) {
      return true;
    }
    queue.pop();
  }
  return false;
}

bool isPossibleOrder(int numberOfTrainFromA, queue<int> trainTargetOrder) {
  queue<int> trainOrderFromA;
  stack<int> station;
  for (int i = 1; i <= numberOfTrainFromA; i++) {
    trainOrderFromA.push(i);
  }

  for (int i = 0; i < numberOfTrainFromA; i++) {
    if (isInQueue(trainTargetOrder.front(), trainOrderFromA)) {
      // Do loop until the that number is in the station
      while (trainOrderFromA.front() != trainTargetOrder.front()) {
        station.push(trainOrderFromA.front());
        trainOrderFromA.pop();
      };
      station.push(trainOrderFromA.front());
      trainOrderFromA.pop();
    } else {
      // If train on the top not = target and not in the trainOrderFromA
      // means that it is impossible
      if (station.top() != trainTargetOrder.front()) {
        return false;
      }
    }
    station.pop();
    trainTargetOrder.pop();
  }
  return true;
}

int main() {
  queue<int> possible;
  while (true) {
    int n;
    cin >> n;
    if (n == 0) {
      break;
    }
    bool isContinueLoop = true;
    while (true) {
      queue<int> trainTargetOrder;
      for (int i = 0; i < n; i++) {
        int orderNumber;
        cin >> orderNumber;
        if (orderNumber == 0) {
          possible.push(-1);
          isContinueLoop = false;
          break;
        }
        trainTargetOrder.push(orderNumber);
      }
      if (!isContinueLoop) {
        break;
      }
      possible.push(isPossibleOrder(n, trainTargetOrder));
    }
  }

  int size = possible.size();
  for (int i = 0; i < size; i++) {
    if (possible.front() == -1) {
      cout << endl;
    } else {
      if (possible.front() == 1) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
    possible.pop();
  }
  return 0;
}

#include <iostream>

using namespace std;

struct Node {
  int value;
  Node *next;
  Node(int value, Node *next = nullptr) : value(value), next(next) {}
};

int main() {
  int n, m;
  cin >> n >> m;
  Node *dummyNode = new Node(-1);
  Node *currentNode = dummyNode;
  Node *previousNode = dummyNode;
  Node *lastNode = nullptr;
  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
    Node *newNode = new Node(value);
    currentNode->next = newNode;
    currentNode = newNode;
  }

  lastNode = currentNode;
  currentNode = dummyNode->next;

  // Previous Node = dummyNode;
  // current Node = First Node;
  for (int i = 0; i < m; i++) {
    int target, sum;
    cin >> target;
    sum = 0;
    while (true) {
      sum += currentNode->value;
      if (sum >= target) {
        // cout << "Drop: " << currentNode->value << endl;
        // Current Node must be dropped.
        previousNode->next = currentNode->next;
        currentNode = currentNode->next;
        if (currentNode == nullptr) {
          // Back to first card.
          currentNode = dummyNode->next;
          previousNode = dummyNode;
        }
        // cout << "Current Node: " << currentNode->value << endl;
        // cout << "Previous Node: " << previousNode->value << endl;
        break;
      }
      previousNode = currentNode;
      currentNode = currentNode->next;
      if (currentNode == nullptr) {
        // Back to first card.
        currentNode = dummyNode->next;
        previousNode = dummyNode;
      }
    }
  }

  // Print linked list chain
  currentNode = dummyNode->next;
  while (currentNode != nullptr) {
    cout << currentNode->value << endl;
    currentNode = currentNode->next;
  }
  return 0;
}

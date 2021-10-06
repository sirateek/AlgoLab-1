#include <iostream>

using namespace std;

struct Node {
  int bonus;
  Node *next;
  Node(int bonus = 0, Node *next = nullptr) : bonus(bonus), next(next) {}
};

int main() {
  int n, m;
  cin >> n >> m;
  Node *dummyNode = new Node(-1);
  Node *currentNode = dummyNode;

  for (int i = 0; i < n; i++) {
    Node *newNode = new Node();
    currentNode->next = newNode;
    currentNode = newNode;
  }
  currentNode = dummyNode->next;
  for (int i = 0; i < m; i++) {
    int action;
    cin >> action;
    if (action == 0) {
      currentNode = dummyNode->next;
    } else if (action == 1) {
      currentNode = currentNode->next;
    } else if (action == 2) {
      Node *newNode = new Node(0, currentNode->next);
      currentNode->next = newNode;
    } else if (action == 3) {
      int x;
      cin >> x;
      currentNode->bonus += x;
    }
  }

  currentNode = dummyNode->next;
  while (currentNode != nullptr) {
    cout << currentNode->bonus << " ";
    currentNode = currentNode->next;
  }
  return 0;
}

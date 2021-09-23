#include <iostream>

using namespace std;

struct Node {
  string name;
  Node *next;

  Node(string name, Node *next = nullptr) : name(name), next(next) {}
};

void addStack(Node *&currentNode, string name) {
  Node *newNode = new Node(name);
  currentNode->next = newNode;
  currentNode = newNode;
}

Node *popStack(Node *dummyNode, Node *&currentNode) {
  if (currentNode->name == "Dummy") {
    return currentNode;
  }
  int count = 0;
  Node *previousTrackNode;
  Node *trackNode;
  while (dummyNode != currentNode) {
    if (count != 0) {
      previousTrackNode = trackNode;
    }
    previousTrackNode = dummyNode;
    count++;
    dummyNode = dummyNode->next;
  }
  currentNode = previousTrackNode;
  return trackNode;
}

int main() {
  int n;
  cin >> n;
  Node *dullNode = new Node("Dummy");
  Node *currentNode = dullNode;
  for (int i = 0; i < n; i++) {
    string command;
    cin >> command;
    if (command == "Sleep") {
      // Add Stack
      string name;
      cin >> name;
      addStack(currentNode, name);
    } else if (command == "Kick") {
      // Pop stack
      popStack(dullNode, currentNode);
    } else {
      // Test
      if (currentNode->name == "Dummy") {
        cout << "Not in a dream" << endl;
      } else {
        cout << currentNode->name << endl;
      }
    }
  }
  return 0;
}

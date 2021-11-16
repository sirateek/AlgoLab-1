#include <iostream>

using namespace std;

struct bstNode {
  int data;
  bstNode *left;
  bstNode *right;

  bstNode(int data, bstNode *left, bstNode *right)
      : data(data), left(left), right(right) {}
};

void insert(bstNode *&root, int data) {
  if (root == nullptr) {
    root = new bstNode(data, nullptr, nullptr);
  } else if (data <= root->data) {
    insert(root->left, data);
  } else {
    insert(root->right, data);
  }
}

bool search(bstNode *root, int data) {
  if (root == nullptr) {
    return false;
  } else if (root->data == data) {
    return true;
  } else if (root->data >= data) {
    return search(root->left, data);
  } else {
    return search(root->right, data);
  }
}

int main() {
  int m;
  cin >> m;
  bstNode *root = nullptr;
  for (int i = 0; i < m; i++) {
    int command, value;
    cin >> command >> value;
    if (command == 1) {
      insert(root, value);
    } else if (command == 2) {
      cout << search(root, value) << endl;
    }
  }

  return 0;
}

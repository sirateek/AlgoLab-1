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
    return;
  } else if (root->data >= data) {
    insert(root->left, data);
  } else {
    insert(root->right, data);
  }
}

void print_node(bstNode *root, int level = 0) {
  if (root == nullptr) {
    return;
  }
  level++;
  print_node(root->right, level);
  for (int i = 0; i < level - 1; i++) {
    cout << "...";
  }
  cout << "* ";
  cout << root->data << endl;
  print_node(root->left, level);
}
int main() {
  int n;
  cin >> n;
  bstNode *root = NULL;
  for (int i = 0; i < n; i++) {
    int data;
    cin >> data;
    insert(root, data);
  }

  print_node(root);
  return 0;
}

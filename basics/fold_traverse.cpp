/*
 * fold_traverse.cpp
 *
 *  Created on: 29-Apr-2018
 *      Author: maran
 */
#include "../ihelper.h"

struct Node {
  int i;
  Node *left;
  Node *right;
  Node(int i_ = 0) : i {i_}, left {nullptr}, right {nullptr} {}
};

// decltype(left) == Node* Node::*
auto left = &Node::left;
auto right = &Node::right;

// Root is Node*
template <typename Root, typename... Path>
Root tree_traverse(Root &&root, Path&&... path) {
  return (root ->* ... ->* path);
}

int main() {
  Node *n1 = new Node {0};
  n1->right= new Node {1};
  n1->right->left= new Node {2};
  cout << tree_traverse(n1, right, left)->i << endl;
  cout << tree_traverse(n1, right)->i << endl;
}

#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};


// Function to create a new node
node* createNode(int key) {
    node* newNode = new node;
    newNode->key = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root != NULL) {
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
  }
}

// Insert a node
struct node* insertNode(struct node* node, int key) {
    // If the tree is empty, create a new node and set it as the root
    if (node == nullptr) {
        node = createNode(key);
        return node;
    }
    // Otherwise, traverse the tree to find the correct position to insert the new node
    else {
        // If the data is less than the root node, insert it into the left subtree
        if (key < node->key) {
            node->left = insertNode(node->left, key);
        }
        // If the data is greater than the root node, insert it into the right subtree
        else {
            node->right = insertNode(node->right, key);
        }
        return node;
    }
}

// Find the inorder successor
struct node *inorderSuccessor(struct node *root) {
  struct node *current = root;
  while (current && current->left != NULL)
    current = current->left;
  return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL)
    return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    // Node with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      delete root;
      return temp;
    }
    else if (root->right == NULL) {
      struct node *temp = root->left;
      delete root;
      return temp;
    }

    // Node with two children: Get the inorder successor (smallest
    // in the right subtree)
    struct node *temp = inorderSuccessor(root->right);

    // Copy the inorder successor's content to this node
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }

  cout << "Inorder traversal: ";
  traverseInOrder(root);

  return 0;
}

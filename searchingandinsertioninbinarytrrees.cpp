#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left == NULL) {
            temp->left = new Node(value);
            break;
        } else {
            q.push(temp->left);
        }

        if (temp->right == NULL) {
            temp->right = new Node(value);
            break;
        } else {
            q.push(temp->right);
        }
    }

    return root;
}

bool search(Node* root, int key) {
    if (root == NULL) return false;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->data == key) return true;

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }

    return false;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;

    root = insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    int key = 30;
    if (search(root, key))
        cout << "\nFound";
    else
        cout << "\nNot Found";

    return 0;
}

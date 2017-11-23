#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int cnt = 0;

class Node {
public:
    int data;
    Node * left;
    Node * right;
    Node() : Node(0) {}
    Node(int k) : data(k), left(nullptr), right(nullptr) {}
};

int traversal(Node * n, int k) {
    if (!n->left && !n->right) {
        if (++cnt == k) return n->data;
        return -1;
    }
    
    int left = -1, right = -1;
    if (n->left) {
        left = traversal(n->left, k);
        if (left != -1) return left;
    }
    
    if (++cnt == k) return n->data;
    
    if (n->right){
        right = traversal(n->right, k);
        if (right != -1) return right;
    }
    return -1;
}

Node * insert(Node * n, int key) {
    if (n == nullptr) return new Node(key);
    
    if (key < n->data) n->left = insert(n->left, key);
    else if (key > n->data) n->right = insert(n->right, key);
    return n;
}

int main() {
    Node * root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    for (int i = 1; i <= 7; ++i) {
        cnt = 0;
        cout << traversal(root, i) << endl;
    }
    
    return 0;
}


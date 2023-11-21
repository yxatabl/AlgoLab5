#include <iostream>
#include <vector>

using namespace std;

struct Node {
    long long data;
    Node* left;
    Node* right;
};

Node* newNode(long long data) {
    Node* node = new Node;
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node* buildTree(vector<long long>& arr, int start, int end) {
    if (start > end) {
        return nullptr;
    }
    int mid = (start + end) / 2;
    Node* root = newNode(arr[mid]);
    root->left = buildTree(arr, start, mid - 1);
    root->right = buildTree(arr, mid + 1, end);
    return root;
}

void preorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Node* root = buildTree(arr, 0, n - 1);
    preorderTraversal(root);
    return 0;
}
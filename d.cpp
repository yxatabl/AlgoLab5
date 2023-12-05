#include <iostream>

using namespace std;

class BST{
    struct Node {
        long long key;
        Node* left;
        Node* right;

        Node(long long val) {
            key = val;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root;
        
    Node* insert(Node* root, long long val, int &level) {
        if (root == nullptr) {
            return new Node(val);
        }

        if (val == root->key) return root;

        if (val < root->key) {
            root->left = insert(root->left, val, ++level);
        }
        else {
            root->right = insert(root->right, val, ++level);
        }
        return root;
    }

    Node* search(Node* root, long long val) {
        if (root == nullptr || root->key == val) {
            return root;
        }
        if (val < root->key) {
            return search(root->left, val);
        }
        else {
            return search(root->right, val);
        }
    }

    Node* minNode(Node* node) {
        Node* current = node;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    Node* deleteNode(Node* root, long long key) {
        if (root == nullptr) {
            return root;
        }
        if (key < root->key) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
        return root;
    }

    Node* prev(Node* root, long long target) {
        Node* el = nullptr;
        Node* curr = root;

        while (curr != nullptr) {
            if (curr->key < target) {
                el = curr;
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        return el;
    }

    Node* next(Node* root, long long target) {
        Node* successor = nullptr;

        while (root != nullptr) {
            if (root->key > target) {
                successor = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }

        return successor;
    }

    bool exists(Node* root, long long target){
        if (root == nullptr) return false;
        if (root->key == target) return true;
        if (root->key < target) return exists(root->right, target);
        if (root->key > target) return exists(root->left, target);
    }

    public:
    BST(){
        root = nullptr;
    }

    int add(long long num){
        int level = 0;
        root = insert(root, num, level);
        return level;
    }

    void remove(long long num){
        root = deleteNode(root, num);
    }

    bool exists(long long num){
        return exists(root, num);
    }

    long long* next(long long num){
        Node* nd = next(root, num);
        if (nd == nullptr) return nullptr; else return &nd->key;
    }

    long long prev(long long num){
        Node* nd = prev(root, num);
        if (nd == nullptr) return -1; else return nd->key;
    }
};

int main(){
    BST bst = BST();
    int n;
    int level;
    int mlevel = -1;
    long long num;

    cin >> n;
    long long maxs[n] = {0};

    for (int i = 0; i < n; i++){
        cin >> num;
        level = bst.add(num);
        maxs[level] = num > maxs[level] ? num : maxs[level];
        mlevel = level > mlevel ? level : mlevel;
    }

    for (int i = 0; i <= mlevel; i++){
        cout << maxs[i] << " ";
    }
}
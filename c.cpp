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
        
    Node* insert(Node* root, long long val) {
        if (root == nullptr) {
            return new Node(val);
        }

        if (val == root->key) return root;

        if (val < root->key) {
            root->left = insert(root->left, val);
        }
        else {
            root->right = insert(root->right, val);
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

    void add(long long num){
        root = insert(root, num);
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

    long long reverseInorderTraversal(Node* node, long long &k){
        if (node == nullptr) return -1;
        
        long long right = reverseInorderTraversal(root->right, k); 
        if (k == 0 && right){
            return right;
        }
        
        k--;
        if (k == 0) return root->key;

        return reverseInorderTraversal(root->left, k);
    }

    long long findKmax(long long k){
        Node* curr = root;
        Node* Klargest = nullptr;
        int count = 0;
        while (curr != nullptr) {
            if (curr->right == nullptr) {
                if (++count == k) Klargest = curr;
                curr = curr->left;
            } else {
                Node* succ = curr->right;
                while (succ->left != nullptr && succ->left != curr) succ = succ->left;
                if (succ->left == nullptr) {
                    succ->left = curr;
                    curr = curr->right;
                } else {
                    succ->left = nullptr;
                    if (++count == k) Klargest = curr;
                    curr = curr->left;
                }
            }
        }

        return Klargest->key;
    }
};

int main(){
    int n;
    long long k;
    char op[5];
    BST bst = BST();
    
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> op >> k;
        if (op[0] == '1'){
            bst.add(k);
        } else if (op[0] == '0'){
            k = bst.findKmax(k);
            cout << k << "\n";
        } else if (op[0] == '-'){
            bst.remove(k);
        }
    }
}
#include <iostream>
#include <cstring>

using namespace std;

struct Node{
    long long key;
    Node *left = nullptr;
    Node *right = nullptr;
    Node *parent = nullptr;

    Node(long long num, Node* dad = nullptr){
        key = num;
        parent = dad;
    }
};

Node* search(Node *x, long long k){
    if (x == nullptr || k == x->key){
        return x;
    } else if (k < x->key){
        return search(x->left, k);
    } else {
        return search(x->right, k);
    }
}

Node* insert(Node* node, long long key){
    Node *parent = node;

    if (node == nullptr){
        Node *nd = new Node(key, parent);
        return nd;
    }
    
    if (key < node->key ){
        node->left = insert(node->left, key);
    } else {
        node->right = insert(node->right, key);
    }
    return node;
}

Node* minValueNode(Node* node){
    Node *current = node;

    while (current->left != nullptr){
        current = current->left;
    }

    return current;
}

Node* maxValueNode(Node* node){
    Node *current = node;

    while(current->right != nullptr){
        current = current->right;
    }

    return current;
}

Node* deleteNode(Node* root, long long key){
    if (root == nullptr){
        return root;
    }

    if (key < root->key){
        root->left = deleteNode(root->left, key);
    } else if (key > root->key){
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr){
            Node *temp = root->right;
            root = nullptr;
            return temp;
        } else if (root->right == nullptr){
            Node *temp = root->left;
            root = nullptr;
            return temp;
        }

        Node *temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

int main(){
    char command[10];
    Node* root = nullptr;
    root->key;
    while (cin >> command){
        if (!strcmp(command, "insert")){
            long long x;
            cin >> x;

            root = insert(root, x);
        } else if (!strcmp(command, "exists")){
            long long x;
            cin >> x;

            Node* res = search(root, x);
            if (res == nullptr) cout << "false"; else cout << "true"; 
            cout << "\n";
        } else if (!strcmp(command, "delete")){
            long long x;
            cin >> x;
            root = deleteNode(root, x);
        } else if (!strcmp(command, "next")){
            long long x;
            cin >> x;
        } else if (!strcmp(command, "prev")){
            long long x;
            cin >> x;
        }
    }
}
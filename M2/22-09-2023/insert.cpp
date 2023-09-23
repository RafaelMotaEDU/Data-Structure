#include <iostream>

using namespace std;

template<typename T>
struct Node {
    T info;
    Node *left=NULL, *right=NULL;
};

template<typename T>
void preFixed(Node<T> *root){
    if(root == NULL) return;
    cout << root->info << " ";
    preFixed<T>(root->left);
    preFixed<T>(root->right);
}

template<typename T>
void innerFixed(Node<T> *root){
    if(root == NULL) return;
    innerFixed<T>(root->left);
    cout << root->info << " ";
    innerFixed<T>(root->right);
}

template<typename T>
void posFixed(Node<T> *root){
    if(root == NULL) return;
    posFixed<T>(root->left);
    posFixed<T>(root->right);
    cout << root->info << " ";
}
template<typename T>
int counterNodes(Node<T> *root){
    if(root == NULL) return 0;
    return 1 + counterNodes(root->left) + counterNodes(root->right);

}
template<typename T>
bool searchCharInNode (Node<T> *root, T value){
    if(root == NULL) return false;
    if(root->info == value) return true;
    return searchCharInNode(root->left, value) || searchCharInNode(root->right, value);
}

template<typename T>
void removeNode(Node<T> *root) {
    if(root == NULL) return;
    remove(root->left);
    remove(root->right);
    delete root;
}

template <typename T>
bool insert(Node<T> *&root, T value){
    if(root == NULL){
        root = new Node<T>;
        root->info = value;
        return true;
    }

    if(root->info == value) return false;

    if(root->info > value){
        return insert(root->left, value);
    } else {
        return insert(root->right, value);
    }
}

int main(){
    Node<char> *root = NULL;
    insert<char>(root, 'A');
    insert<char>(root, 'B');
    insert<char>(root, 'C');
    cout<< "PRE: ";
    preFixed(root);
    cout << endl;
    cout<< "IN: ";
    innerFixed(root);
    cout << endl;
    cout<< "POS: ";
    posFixed(root);
}

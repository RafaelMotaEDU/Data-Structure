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
    removeNode(root->left);
    removeNode(root->right);
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

template <typename T>
T searchBiggest(Node<T> *root){
    if(root->right != NULL) return searchBiggest(root->right);
    return root->info;
}

template <typename T>
bool remove (Node<T> *&root, T value){
    if(root == NULL) return false;
    if(root->info == value){
        Node<T> *auxRootPointer = root;
        if(root->left == NULL && root->right == NULL){
            root = NULL;
            delete auxRootPointer;
            return true;
        }

        if(root->left == NULL && root->right != NULL){
            root = root->right;
            delete auxRootPointer;
            return true;
        }

        if(root->left != NULL && root->right == NULL){
            root = root->left;
            delete auxRootPointer;
            return true;
        }

        T info_aux = searchBiggest(root->left);
        root->info = info_aux;
        return remove(root->left, info_aux);

    }

    if(value < root->info)
        return remove(root->left, value);
    else
        return remove(root->right, value);
}

int main(){
    Node<char> *root = NULL;
    insert<char>(root, 'P');
    insert<char>(root, 'E');
    insert<char>(root, 'R');
    insert<char>(root, 'N');
    insert<char>(root, 'A');
    insert<char>(root, 'M');
    insert<char>(root, 'B');
    insert<char>(root, 'U');
    insert<char>(root, 'C');
    insert<char>(root, 'O');

    cout<< "PRE: ";
    preFixed(root);
    cout << endl;
    cout<< "IN: ";
    innerFixed(root);
    cout << endl;
    cout<< "POS: ";
    posFixed(root);
    cout << endl;
    remove(root, 'P');

    cout<<endl;
    cout<< "DELETE: " << endl;
    cout<<endl;

    cout<< "PRE: ";
    preFixed(root);
    cout << endl;
    cout<< "IN: ";
    innerFixed(root);
    cout << endl;
    cout<< "POS: ";
    posFixed(root);
    cout << endl;
}

#include <iostream>

using namespace std;

struct Node {
    char info;
    Node *left=NULL, *right=NULL;
};

void preFixed(Node *root){
    if(root == NULL) return;
    cout << root->info << " ";
    preFixed(root->left);
    preFixed(root->right);
}

void innerFixed(Node *root){
    if(root == NULL) return;
    innerFixed(root->left);
    cout << root->info << " ";
    innerFixed(root->right);
}

void posFixed(Node *root){
    if(root == NULL) return;
    posFixed(root->left);
    posFixed(root->right);
    cout << root->info << " ";
}

int main(){
    Node *root, *node1, *node2, *node3, *node4, *node5;

    root = new Node;
    root->info = 'B';

    node1 = new Node;
    node1->info = 'A';
    node2 = new Node;
    node2->info = 'C';
    node3 = new Node;
    node3->info = 'D';
    node4 = new Node;
    node4->info = 'E';

    node5 = new Node;
    node5->info = 'G';

    root->left = node1;
    root->right = node2;

    node2->left = node3;
    node2->right = node4;
    node4->right = node5;

    cout << "Pre: ";
    preFixed(root);
    cout<<endl;
    cout << "In:  ";
    innerFixed(root);
    cout<<endl;
    cout << "Pos: ";
    posFixed(root);
}

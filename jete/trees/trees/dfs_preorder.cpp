#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node *left, *right;

    Node(int val): val(val), left(nullptr), right(nullptr) {}
};

void dfs(Node* root) {
    if(root == nullptr) return;

    cout<<root->val<<"->";
    if(root->left) dfs(root->left);
    if(root->right) dfs(root->right);
}

/*
 *            1
 *       2        3
 *     4    5   6   7
 *
 */

int main() {
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    dfs(root);
    cout<<"nullptr"<<endl;
    return 0;
}

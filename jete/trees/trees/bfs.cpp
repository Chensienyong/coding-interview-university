#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node *left, *right;

    Node(int val): val(val), left(nullptr), right(nullptr) {}
};

void bfs(Node* root) {
    if(root == nullptr) return;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            Node* curr = q.front();
            cout<<curr->val<<"->";

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);

            q.pop();
        }
    }
    cout<<"nullptr"<<endl;
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

    bfs(root);
    return 0;
}

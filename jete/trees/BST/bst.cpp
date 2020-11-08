#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node *left, *right;

    Node(int val): val(val), left(nullptr), right(nullptr) {};
};

class BST {
private:
    Node* root;

    Node* insert_recurse(Node* head, int val) {
        if(val < head->val) {
            if(head->left) {
                head->left = insert_recurse(head->left, val);
            } else {
                head->left = new Node(val);
            }
        } else {
            if(head->right) {
                head->right = insert_recurse(head->right, val);
            } else {
                head->right = new Node(val);
            }
        }
        return head;
    }

    void dfs_print_inorder(Node* head) {
        if(head->left) dfs_print_inorder(head->left);
        cout<<head->val<<" ";
        if(head->right) dfs_print_inorder(head->right);
    }

    Node* dfs_delete_postorder(Node* head) {
        if(head == nullptr) return head;

        head->left = dfs_delete_postorder(head->left);
        head->right = dfs_delete_postorder(head->right);

        delete head;
        return nullptr;
    }

    bool dfs_search(Node* head, int val) {
        if(head == nullptr) return false;

        if(val < head->val) return dfs_search(head->left, val);
        else if(val > head->val) return dfs_search(head->right, val);
        else return true;
    }

    bool validate_bst(Node* head, bool min_flag, bool max_flag, int min, int max) {
        if(head == nullptr) return true;

        if(min_flag && head->val < min) return false;
        if(max_flag && head->val > max) return false;
        return validate_bst(head->left, min_flag, true, min, head->val) && validate_bst(head->right, true, max_flag, head->val, max);
    }

    Node* get_min_from_tree(Node* head) {
        while(head->left) head = head->left;
        return head;
    }

    Node* dfs_delete_value(Node* head, int val) {
        if(head == nullptr) return head;

        if(val < head->val) head->left = dfs_delete_value(head->left, val);
        else if(val > head->val) head->right = dfs_delete_value(head->right, val);
        else {
            if(!head->left && !head->right) {
                delete(head);
                return nullptr;
            } else if(head->left && !head->right) {
                Node* temp = head->left;
                delete(head);
                return temp;
            } else if(!head->left && head->right) {
                Node* temp = head->right;
                delete(head);
                return temp;
            } else {
                Node* temp = get_min_from_tree(head->right);
                head->val = temp->val;
                head->right = dfs_delete_value(head->right, temp->val);
            }
        }

        return head;
    }
public:
    BST() {
        root = nullptr;
    }

    void insert(int val) {
        if(!root) {
            root = new Node(val);
            return;
        }

        root = insert_recurse(root, val);
    }

    int get_node_count() {
        if(root == nullptr) return 0;

        queue<Node*> q;
        int size = 0;

        q.push(root);
        while(!q.empty()) {
            size++;
            Node* front = q.front();

            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);

            q.pop();
        }
        return size;
    }

    void print_values() {
        if(root == nullptr) {
            cout<<"Binary Search Tree is empty!"<<endl;
            return;
        }

        dfs_print_inorder(root);
    }

    void delete_tree() {
        root = dfs_delete_postorder(root);
    }

    bool is_in_tree(int val) {
        if(dfs_search(root, val)) return true;
        return false;
    }

    int get_height() {
        int height = 0;
        if(root == nullptr) return height;

        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            height++;
            int size = q.size();
            while(size--) {
                Node* front = q.front();
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                q.pop();
            }
        }
        return height;
    }

    int get_min() {
        if(root == nullptr) return -1;
        Node* curr = root;
        while(curr->left) curr = curr->left;
        return curr->val;
    }

    int get_max() {
        if(root == nullptr) return -1;
        Node* curr = root;
        while(curr->right) curr = curr->right;
        return curr->val;
    }

    bool is_binary_search_tree() {
        return validate_bst(root, false, false, INT_MIN, INT_MAX);
    }

    void delete_value(int val) {
        dfs_delete_value(root, val);
    }

    int get_successor(int val) {
        Node* succestor = nullptr;
        Node* ancestor = root;
        while(ancestor) {
            if(val < ancestor->val) {
                succestor = ancestor;
                ancestor = ancestor->left;
            } else if(val > ancestor->val) {
                ancestor = ancestor->right;
            } else {
                if(ancestor->right) {
                    ancestor = ancestor->right;
                    while(ancestor->left) ancestor = ancestor->left;
                    return ancestor->val;
                } else {
                    if(succestor == nullptr) return -1;
                    else return succestor->val;
                }
            }
        }
        return -1;
    }
};

void test_node() {
    int value = rand() % 10;
    Node* node = new Node(value);
    assert(node->val == value);
    assert(node->left == nullptr);
    assert(node->right == nullptr);
}

void test_constructor() {
    BST* bst = new BST();
    assert(bst->is_binary_search_tree() == true);
}

void test_bst() {
    BST* bst = new BST();
    bst->insert(7);
    bst->insert(4);
    bst->insert(10);
    bst->insert(2);
    bst->insert(6);
    assert(bst->get_min() == 2);
    assert(bst->get_max() == 10);
    assert(bst->get_node_count() == 5);
    assert(bst->is_in_tree(13) == false);
    assert(bst->get_successor(6) == 7);
    bst->insert(8);
    bst->insert(13);
    assert(bst->get_height() == 3);
    bst->insert(1);
    bst->insert(3);
    assert(bst->is_binary_search_tree() == true);
    assert(bst->get_height() == 4);
    assert(bst->get_min() == 1);
    assert(bst->get_max() == 13);
    assert(bst->get_node_count() == 9);
    assert(bst->is_in_tree(13) == true);
    assert(bst->get_successor(13) == -1);
    assert(bst->get_successor(10) == 13);

    bst->delete_value(8);
    assert(bst->is_in_tree(8) == false);
    assert(bst->is_in_tree(10) == true);
    bst->delete_value(4);
    assert(bst->is_in_tree(4) == false);
    assert(bst->is_in_tree(2) == true);
    assert(bst->is_in_tree(6) == true);
    assert(bst->is_binary_search_tree() == true);
    bst->delete_tree();

    assert(bst->get_height() == 0);
    assert(bst->is_binary_search_tree() == true);
    assert(bst->get_min() == -1);
    assert(bst->get_max() == -1);
    assert(bst->get_node_count() == 0);
}

void test() {
    test_node();
    test_constructor();
    test_bst();
}

int main() {
    test();
    return 0;
}

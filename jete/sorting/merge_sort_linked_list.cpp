#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val): val(val), next(nullptr) {}
    Node(): val(0), next(nullptr) {}
};

pair<Node*, Node*> divideNode(Node* root) {
    Node *slow, *fast;
    slow = fast = root;
    while(fast->next != nullptr && fast->next->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node* right = slow->next;
    slow->next = nullptr;
    return {root, right};
}

Node* sortTwoNodes(Node* left, Node* right) {
    Node* res = nullptr;
    if(left == nullptr) return right;
    if(right == nullptr) return left;

    if(left->val <= right->val) {
        res = left;
        res->next = sortTwoNodes(left->next, right);
    } else {
        res = right;
        res->next = sortTwoNodes(left, right->next);
    }
    return res;
}

Node* mergeSort(Node* root) {
    if(root == nullptr || root->next == nullptr) return root;

    pair<Node*, Node*> p = divideNode(root);

    Node* left = mergeSort(p.first);
    Node* right = mergeSort(p.second);

    return sortTwoNodes(left, right);
}

void test_node() {
    int value = rand() % 10;
    Node* node = new Node(value);
    assert(node->val == value);
    assert(node->next == nullptr);
}

void test_mergesort() {
    vector<int> in = {5,7,9,3,10,2,6,1,4,8};
    Node* root = new Node();
    Node* head = root;
    for(auto e: in) {
        head->next = new Node(e);
        head = head->next;
    }
    root = root->next;
    Node* sorted = mergeSort(root);
    sort(in.begin(), in.end());
    for(auto e: in) {
        assert(e == sorted->val);
        sorted = sorted->next;
    }
}

void test() {
    test_node();
    test_mergesort();
}

int main() {
    test();
    return 0;
}

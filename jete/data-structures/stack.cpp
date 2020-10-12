#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        next = nullptr;
    }
};

class Stack {
private:
    Node* head;
public:
    Stack() {
        head = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    int pop() {
        if(head == nullptr) {
            cout<<"No entry to be popped."<<endl;
            return -1;
        }

        int top = head->val;
        head = head->next;
        return top;
    }

    int top() {
        if(head == nullptr) {
            cout<<"No entry on the stack."<<endl;
            return -1;
        }
        return head->val;
    }

    bool empty() {
        return head == nullptr;
    }
};

void test_node() {
    int value = rand() % 10;
    Node* node = new Node(value);
    assert(node->val == value);
    assert(node->next == nullptr);
}

void test_constructor() {
    Stack* stack = new Stack();
    assert(stack->empty() == true);
}

void test_stack() {
    Stack* stack = new Stack();
    stack->push(1);
    assert(stack->top() == 1);
    assert(stack->empty() == false);

    assert(stack->pop() == 1);
    assert(stack->empty() == true);

    stack->push(2);
    assert(stack->top() == 2);
    assert(stack->empty() == false);

    stack->push(3);
    assert(stack->top() == 3);
    assert(stack->empty() == false);

    assert(stack->pop() == 3);
    assert(stack->top() == 2);
    assert(stack->empty() == false);

    stack->push(4);
    assert(stack->top() == 4);
    assert(stack->empty() == false);

    assert(stack->pop() == 4);
    assert(stack->top() == 2);
    assert(stack->empty() == false);

    assert(stack->pop() == 2);
    assert(stack->empty() == true);
}

void test() {
    test_node();
    test_constructor();
    test_stack();
}

int main() {
    test();
    return 0;
}

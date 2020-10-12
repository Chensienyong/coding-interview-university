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

class Queue {
private:
    Node *head, *tail;
public:
    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if(tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int dequeue() {
        if(head == nullptr) {
            cout<<"No entry to be dequeue."<<endl;
            return -1;
        }

        int front = head->val;
        if(head == tail) {
            tail = nullptr;
        }
        head = head->next;
        return front;
    }

    int front() {
        if(head == nullptr) {
            cout<<"No entry on the queue."<<endl;
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
    Queue* queue = new Queue();
    assert(queue->empty() == true);
}

void test_queue() {
    Queue* queue = new Queue();
    queue->enqueue(1);
    assert(queue->front() == 1);
    assert(queue->empty() == false);

    assert(queue->dequeue() == 1);
    assert(queue->empty() == true);

    queue->enqueue(2);
    assert(queue->front() == 2);
    assert(queue->empty() == false);

    queue->enqueue(3);
    assert(queue->front() == 2);
    assert(queue->empty() == false);

    assert(queue->dequeue() == 2);
    assert(queue->front() == 3);
    assert(queue->empty() == false);

    queue->enqueue(4);
    assert(queue->front() == 3);
    assert(queue->empty() == false);

    assert(queue->dequeue() == 3);
    assert(queue->front() == 4);
    assert(queue->empty() == false);

    assert(queue->dequeue() == 4);
    assert(queue->empty() == true);
}

void test() {
    test_node();
    test_constructor();
    test_queue();
}

int main() {
    test();
    return 0;
}

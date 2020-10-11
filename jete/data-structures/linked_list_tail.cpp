
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

class MyLinkedList {
private:
    Node* root;
    Node* tail;
    int lSize;
public:
    MyLinkedList() {
        root = nullptr;
        tail = nullptr;
        lSize = 0;
    }

    int size() {
        return lSize;
    }

    bool empty() {
        return lSize == 0;
    }

    int value_at(int index) {
        if(index >= lSize) {
            cout<<"No value at index "<<index<<"."<<endl;
            return -1;
        }
        Node* head = root;
        while(index--) {
            head = head->next;
        }
        return head->val;
    }

    void push_front(int value) {
        Node* newNode = new Node(value);
        newNode->next = root;

        if(lSize == 0) {
            tail = root;
        }

        root = newNode;
        lSize++;
    }

    int pop_front() {
        if(root == nullptr) {
            cout<<"No data to be pop."<<endl;
            return -1;
        }
        int value = root->val;
        root = root->next;

        if(lSize == 1) {
            tail = root;
        }

        lSize--;
        return value;
    }

    void push_back(int value) {
        Node* newNode = new Node(value);

        if(lSize == 0) {
            root = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;

        lSize++;
    }

    int pop_back() {
        if(root == nullptr) {
            cout<<"No data to be pop."<<endl;
            return -1;
        }

        int res;
        if(lSize == 1) {
            res = root->val;
            root = tail = nullptr;
        } else {
            Node* head = root;
            while(head->next->next != nullptr) {
                head = head->next;
            }
            res = head->next->val;
            head->next = nullptr;
            tail = head;
        }
        lSize--;

        return res;
    }

    int front() {
        if(root == nullptr) {
            cout<<"No node existed."<<endl;
            return -1;
        }
        return root->val;
    }

    int back() {
        if(tail == nullptr) {
            cout<<"No node existed."<<endl;
            return -1;
        }

        return tail->val;
    }

    void insert(int index, int value) {
        if(index > lSize) {
            cout<<"Index is bigger than the size."<<endl;
        }

        Node* newNode = new Node(value);
        if(index == 0) {
            newNode->next = root;
            root = newNode;
        } else {
            index--;
            Node* head = root;
            while(index--) {
                head = head->next;
            }
            Node* nextNode = head->next;
            newNode->next = nextNode;
            head->next = newNode;
        }
        lSize++;
    }

    void erase(int index) {
        if(index >= lSize) {
            cout<<"Index is bigger than the size."<<endl;
        }

        if(index == 0) {
            root = root->next;
        } else {
            Node* head = root;
            index--;
            while(index--) {
                head = head->next;
            }
            head->next = head->next->next;
        }
        lSize--;
    }

    int value_n_from_end(int n) {
        if(n >= lSize) {
            cout<<"Index is bigger than the size."<<endl;
            return -1;
        }

        int reverseIndex = lSize-1;
        Node* head = root;
        while(reverseIndex-- != n) {
            head = head->next;
        }
        return head->val;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* head = root;
        while(head != nullptr) {
            Node* temp = head;
            head = head->next;
            temp->next = prev;
            prev = temp;
        }
        root = prev;
    }

    int remove_value(int value) {
        Node* head = root;
        int index = 0;
        while(head != nullptr) {
            if(head->val == value) {
                erase(index);
                return index;
            }
            index++;
        }

        cout<<"No linked list found"<<endl;
        return -1;
    }

    void print() {
        Node* head = root;
        while(head != nullptr) {
            cout<<head->val<<"->";
            head = head->next;
        }
        cout<<"null"<<endl;
    }
};

void test_node() {
    int value = rand() % 10;
    Node* node = new Node(value);
    assert(node->val == value);
    assert(node->next == nullptr);
}

void test_constructor() {
    MyLinkedList* list = new MyLinkedList();
    assert(list->size() == 0);
    assert(list->empty() == true);
}

void test_front() {
    MyLinkedList* list = new MyLinkedList();
    list->push_front(1);
    assert(list->size() == 1);
    assert(list->front() == 1);
    assert(list->empty() == false);

    list->push_front(2);
    assert(list->size() == 2);
    assert(list->front() == 2);
    assert(list->empty() == false);
    assert(list->value_at(1) == 1);

    assert(list->pop_front() == 2);
    assert(list->size() == 1);
    assert(list->front() == 1);
    assert(list->empty() == false);

    assert(list->pop_front() == 1);
    assert(list->size() == 0);
    assert(list->empty() == true);
}

void test_back() {
    MyLinkedList* list = new MyLinkedList();
    list->push_back(1);
    assert(list->size() == 1);
    assert(list->back() == 1);
    assert(list->empty() == false);

    list->push_back(2);
    assert(list->size() == 2);
    assert(list->back() == 2);
    assert(list->empty() == false);
    assert(list->value_at(0) == 1);

    assert(list->pop_back() == 2);
    assert(list->size() == 1);
    assert(list->back() == 1);
    assert(list->empty() == false);

    assert(list->pop_back() == 1);
    assert(list->size() == 0);
    assert(list->empty() == true);
}

void test_rest() {
    MyLinkedList* list = new MyLinkedList();
    list->insert(0, 1);
    assert(list->size() == 1);
    assert(list->value_at(0) == 1);
    assert(list->empty() == false);

    list->insert(1, 2);
    assert(list->size() == 2);
    assert(list->value_at(1) == 2);
    assert(list->empty() == false);

    list->insert(0, 0);
    assert(list->size() == 3);
    assert(list->value_at(0) == 0);
    assert(list->empty() == false);

    assert(list->value_n_from_end(0) == 2);
    assert(list->value_n_from_end(1) == 1);
    assert(list->value_n_from_end(2) == 0);

    list->reverse();

    assert(list->value_n_from_end(0) == 0);
    assert(list->value_n_from_end(1) == 1);
    assert(list->value_n_from_end(2) == 2);

    list->erase(1);
    assert(list->size() == 2);
    assert(list->value_at(1) == 0);

    assert(list->remove_value(2) == 0);
    assert(list->size() == 1);

    assert(list->remove_value(0) == 0);
    assert(list->size() == 0);
    assert(list->empty() == true);
}

void test() {
    test_node();
    test_constructor();
    test_front();
    test_back();
    test_rest();
}

int main() {
    test();
    return 0;
}

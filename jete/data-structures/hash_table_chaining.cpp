#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    string key;
    string value;
    Node* next;

    Node(string key, string value): key(key), value(value), next(nullptr) {}
    Node(Node* next): key(""), value(""), next(next) {}
};

class HashTable {
private:
    int size;
    vector<Node*> table;

    int hash(string key, int modulo) {
        int value = 0;
        for(char c: key) value += (int)c;

        return value % modulo;
    }
public:
    HashTable(int size) {
        this->size = size;
        table.reserve(size);

        for(int i=0; i<size; i++) table.push_back(nullptr);
    }

    void add(string key, string value) {
        if(exists(key)) return;

        int index = hash(key, size);
        if(table[index] == nullptr) {
            table[index] = new Node(key, value);
        } else {
            Node* curr = table[index];
            while(curr->next != nullptr) curr = curr->next;

            curr->next = new Node(key, value);
        }
    }

    bool exists(string key) {
        int index = hash(key, size);

        Node* curr = table[index];
        while(curr != nullptr) {
            if(curr->key == key) return true;

            curr = curr->next;
        }
        return false;
    }

    string get(string key) {
        int index = hash(key, size);

        Node* curr = table[index];
        while(curr) {
            if(curr->key == key) return curr->value;

            curr = curr->next;
        }
        return "";
    }

    string remove(string key) {
        int index = hash(key, size);

        string removed = "";
        Node* curr = table[index];
        if(curr == nullptr) return removed;
        if(curr->next == nullptr) {
            if(curr->key == key) {
                removed = curr->value;
                table[index] = nullptr;
            }
        } else {
            Node* prev = new Node(curr);
            Node* root = prev;
            while(curr) {
                if(curr->key == key) {
                    removed = curr->value;

                    prev->next = prev->next->next;
                    break;
                }

                prev = curr;
                curr = curr->next;
            }
            table[index] = root;
        }
        return removed;
    }

    void print(string key) {
        int index = hash(key, size);

        Node* curr = table[index];
        while(curr) {
            cout<<curr->key<<endl;
            curr = curr->next;
        }
    }
};

void test_node() {
    Node* node = new Node("key", "value");
    assert(node->key == "key");
    assert(node->value == "value");
    assert(node->next == nullptr);
}

void test_hash_table() {
    HashTable* hashTable = new HashTable(5);
    assert(hashTable->exists("first") == false);
    assert(hashTable->remove("first") == "");
    assert(hashTable->get("first") == "");

    hashTable->add("first", "a");
    assert(hashTable->exists("first") == true);
    assert(hashTable->get("first") == "a");

    hashTable->add("second", "b");
    assert(hashTable->exists("second") == true);
    assert(hashTable->get("second") == "b");

    hashTable->add("third", "c");
    assert(hashTable->exists("third") == true);
    assert(hashTable->get("third") == "c");

    hashTable->add("fourth", "d");
    assert(hashTable->exists("fourth") == true);
    assert(hashTable->get("fourth") == "d");

    assert(hashTable->remove("third") == "c");
    assert(hashTable->get("third") == "");
    assert(hashTable->remove("first") == "a");
    assert(hashTable->get("first") == "");
}

void test() {
    test_node();
    test_hash_table();
}

int main() {
    test();
    return 0;
}

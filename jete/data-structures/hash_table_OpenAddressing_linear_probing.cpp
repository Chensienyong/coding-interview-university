#include<bits/stdc++.h>

using namespace std;

class Element {
public:
    string key;
    string value;

    Element(string key, string value): key(key), value(value) {}
};

class HashTable {
private:
    int size;
    vector<Element*> table;

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
        while(table[index]) index++;

        table[index] = new Element(key, value);
    }

    bool exists(string key) {
        int index = hash(key, size);

        while(table[index]) {
            if(table[index]->key == key) return true;

            index++;
        }
        return false;
    }

    string get(string key) {
        int index = hash(key, size);

        while(table[index]) {
            if(table[index]->key == key) return table[index]->value;

            index++;
        }
        return "";
    }

    string remove(string key) {
        int index = hash(key, size);

        while(table[index]) {
            if(table[index]->key == key) {
                string removed = table[index]->value;

                table[index] = nullptr;
                return removed;
            }

            index++;
        }
        return "";
    }
};

void test_element() {
    Element* element = new Element("key", "value");
    assert(element->key == "key");
    assert(element->value == "value");
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
    test_element();
    test_hash_table();
}

int main() {
    test();
    return 0;
}

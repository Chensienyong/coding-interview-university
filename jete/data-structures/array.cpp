#include <bits/stdc++.h>

using namespace std;

class MyArray{
private:
    int aCapacity;
    int aSize;
    int* arr;

    void resize() {
        if(aSize == aCapacity) {
            aCapacity *= 2;
            int* temp = new int[aCapacity];

            for(int i=0; i<aSize; i++) {
                temp[i] = arr[i];
            }
            arr = temp;
        }

        if(aCapacity > 4 && aSize <= aCapacity / 4.0) {
            aCapacity /= 2;
            int* temp = new int[aCapacity];

            for(int i=0; i<aSize; i++) {
                temp[i] = arr[i];
            }
            arr = temp;
        }
    }
public:
    MyArray() {
        aCapacity = 1;
        aSize = 0;
        arr = new int[1];
    }

    int size() {
        return aSize;
    }

    int capacity() {
        return aCapacity;
    }

    bool is_empty() {
        return aSize == 0;
    }

    int at(int index) {
        if(index >= aSize) {
            cout<<"Index out of Bounds!\n";
            return -1;
        }
        return arr[index];
    }

    void push(int item) {
        arr[aSize] = item;
        aSize++;
        resize();
    }

    void insert(int index, int item) {
        int* temp = new int[aCapacity];
        for(int i=0; i<index; i++) {
            temp[i] = arr[i];
        }
        temp[index] = item;
        for(int i=index; i<aSize; i++) {
            temp[i+1] = arr[i];
        }
        arr = temp;
        aSize++;
        resize();
    }

    void prepend(int item) {
        insert(0, item);
    }

    int pop() {
        int value = arr[--aSize];

        resize();
        return value;
    }

    int remove(int index) {
        int value = arr[index];
        int* temp = new int[aCapacity];
        for(int i=0; i<index; i++) {
            temp[i] = arr[i];
        }
        for(int i=index; i<aSize-1; i++) {
            temp[i] = arr[i+1];
        }
        aSize--;

        arr = temp;
        resize();
        return value;
    }

    int find(int item) {
        for(int i=0; i<aSize; i++) {
            if(arr[i] == item) return i;
        }
        return -1;
    }
};

void test_constructor() {
    MyArray* arr = new MyArray();
    assert(arr->size() == 0);
    assert(arr->capacity() == 1);
    assert(arr->is_empty() == true);
}

void test_insert() {
    MyArray* arr = new MyArray();
    arr->push(1);
    assert(arr->size() == 1);
    assert(arr->capacity() == 2);
    assert(arr->is_empty() == false);
    assert(arr->at(0) == 1);

    arr->insert(1, 2);
    assert(arr->size() == 2);
    assert(arr->capacity() == 4);
    assert(arr->at(0) == 1);
    assert(arr->at(1) == 2);

    arr->prepend(3);
    assert(arr->size() == 3);
    assert(arr->capacity() == 4);
    assert(arr->at(0) == 3);
    assert(arr->at(1) == 1);
    assert(arr->at(2) == 2);
}

void test_find() {
    MyArray* arr = new MyArray();
    arr->push(1);
    arr->push(2);
    arr->push(3);
    arr->push(4);
    assert(arr->size() == 4);
    assert(arr->capacity() == 8);
    assert(arr->is_empty() == false);
    assert(arr->at(0) == 1);
    assert(arr->at(2) == 3);
    assert(arr->find(2) == 1);
    assert(arr->find(4) == 3);
    assert(arr->find(5) == -1);
}

void test_remove() {
    MyArray* arr = new MyArray();
    arr->push(1);
    arr->push(2);
    arr->push(3);
    arr->push(4);
    assert(arr->size() == 4);
    assert(arr->capacity() == 8);
    assert(arr->is_empty() == false);
    assert(arr->pop() == 4);
    assert(arr->capacity() == 8);
    assert(arr->remove(1) == 2);
    assert(arr->capacity() == 4);
    assert(arr->pop() == 3);
    assert(arr->capacity() == 4);
    assert(arr->remove(0) == 1);
    assert(arr->size() == 0);
    assert(arr->is_empty() == true);
}

void test() {
    test_constructor();
    test_insert();
    test_find();
    test_remove();
}

int main() {
    test();
    return 0;
}

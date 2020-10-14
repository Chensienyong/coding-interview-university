#include<bits/stdc++.h>

using namespace std;

class Queue {
private:
    vector<int> queue;
    int capacity;
    int write;
    int read;

    int nextIndex(int point) {
        return (point+1) % capacity;
    }
public:
    Queue(int size) {
        capacity = size;
        queue.reserve(size);
        write = read = -1;
    }

    void enqueue(int value) {
        if(full()) {
            cout<<"Queue is full."<<endl;
            return;
        }
        if(empty()) {
            read = 0;
            write = 0;
        }
        queue[write] = value;
        write = nextIndex(write);
    }

    int dequeue() {
        if(empty()) {
            cout<<"No entry in queue."<<endl;
            return -1;
        }
        int res = queue[read];
        read = nextIndex(read);
        if(read == write) {
            read = -1;
            write = -1;
        }
        return res;
    }

    int front() {
        if(read == -1) {
            cout<<"No entry in queue."<<endl;
            return -1;
        }
        return queue[read];
    }

    bool empty() {
        return read == -1;
    }

    bool full() {
        return read != -1 && write == read;
    }
};

void test_constructor() {
    Queue* queue = new Queue(3);
    assert(queue->empty() == true);
}

void test_queue() {
    Queue* queue = new Queue(2);
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
    assert(queue->full() == true);

    assert(queue->dequeue() == 2);
    assert(queue->front() == 3);
    assert(queue->empty() == false);

    queue->enqueue(4);
    assert(queue->front() == 3);
    assert(queue->empty() == false);
    assert(queue->full() == true);

    assert(queue->dequeue() == 3);
    assert(queue->front() == 4);
    assert(queue->empty() == false);

    assert(queue->dequeue() == 4);
    assert(queue->empty() == true);
}

void test() {
    test_constructor();
    test_queue();
}

int main() {
    test();
    return 0;
}

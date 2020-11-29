#include<bits/stdc++.h>

using namespace std;

class Heap {
private:
    int* arr;
    int capacity;
    int size;

    int parent(int curr) {
        if(curr == 0) return -1;
        int par = (curr + 1) / 2;
        return par - 1;
    }

    int left(int curr) {
        return curr * 2 + 1;
    }

    int right(int curr) {
        return curr * 2 + 2;
    }

    int get_index(int val) {
        for(int i=0; i<size; i++) {
            if(val == arr[i]) return i;
        }
        return -1;
    }
public:
    Heap(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        size = 0;
    }

    void insert(int val) {
        if(size == capacity) return;
        arr[size] = val;
        sift_up(size);
        size++;
    }

    void sift_up(int idx) {
        while(parent(idx) != -1 && arr[parent(idx)] < arr[idx]) {
            swap(arr[parent(idx)], arr[idx]);
            sift_up(parent(idx));
        }
    }

    int get_max() {
        if(get_size() == 0) return -1;
        return arr[0];
    }

    int get_size() {
        return size;
    }

    bool is_empty() {
        return get_size() == 0;
    }

    int extract_max() {
        print();
        int res = get_max();
        print();
        swap(arr[0], arr[size-1]);
        size -= 1;
        sift_down(0);
        print();
        return res;
    }

    void sift_down(int idx) {
        int l = left(idx);
        int r = right(idx);
        int largest = idx;

        if(l < size && arr[l] > arr[largest]) largest = l;
        if(r < size && arr[r] > arr[largest]) largest = r;
        //cout<<largest<<"-"<<arr[largest]<<endl;

        if(largest != idx) {
            swap(arr[largest], arr[idx]);
            sift_down(largest);
        }
    }

    void remove(int i) {
        int idx = get_index(i);
        if(idx == -1) return;
        arr[idx] = INT_MAX;
        sift_up(idx);
        extract_max();
    }

    void heapify(vector<int> in) {
        size = in.size();
        capacity = size * 2;
        arr = &in[0];

        for(int i=size/2; i>=0; i--) {
            sift_down(i);
        }
    }

    vector<int> heap_sort() {
        int* arr_temp = arr;
        int size_temp = size;

        vector<int> res;
        while(!is_empty()) {
            int temp = extract_max();
            print();
            cout<<temp<<endl;
            //PROBLEM: ARRAY MISTRANSFORMED SOMEHOW
            res.push_back(temp);
            print();
        }
        cout<<"ENDL\n";
        reverse(res.begin(), res.end());
        arr = arr_temp;
        size = size_temp;
        return res;
    }

    void print() {
        for(int i=0; i<size; i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
};

void test_constructor() {
    Heap* heap = new Heap(5);
    assert(heap->is_empty() == true);
    assert(heap->get_max() == -1);
    assert(heap->get_size() == 0);
}

void test_crud() {
    Heap* heap = new Heap(5);
    assert(heap->is_empty() == true);
    assert(heap->get_size() == 0);

    heap->insert(3);
    heap->insert(4);
    assert(heap->is_empty() == false);
    assert(heap->get_size() == 2);
    heap->insert(1);
    heap->insert(2);
    assert(heap->extract_max() == 4);
    assert(heap->get_size() == 3);
    assert(heap->get_max() == 3);
    heap->remove(7);
    assert(heap->get_size() == 3);
    heap->remove(2);
    assert(heap->get_size() == 2);
    heap->insert(6);
    heap->insert(5);
    assert(heap->get_size() == 4);
    assert(heap->extract_max() == 6);
    assert(heap->extract_max() == 5);
    assert(heap->extract_max() == 3);
    assert(heap->get_size() == 1);
    heap->remove(1);
    assert(heap->get_size() == 0);
    assert(heap->is_empty() == true);
}

void test_sort() {
    vector<int> in = {5,7,9,3,10,2,6,1,4,8};
    Heap* heap = new Heap(20);
    assert(heap->is_empty() == true);
    assert(heap->get_size() == 0);
    heap->heapify(in);
    assert(heap->is_empty() == false);
    assert(heap->get_size() == 10);
    vector<int> res = heap->heap_sort();
    for(auto e: res) {
        cout<<e<<" ";
    }
    assert((heap->heap_sort() == vector<int>{1,2,3,4,5,6,7,8,9,10}));
}

void test() {
    test_constructor();
//    test_crud();
    test_sort();
}

int main() {
    test();
    return 0;
}

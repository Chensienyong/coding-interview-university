#include<bits/stdc++.h>

using namespace std;

int binary_search(vector<int> arr, int target, int low, int high) {
    if(low > high) return -1;

    int middle = low + (high - low) / 2;

    if(arr[middle] == target) return middle;
    else if(arr[middle] < target) return binary_search(arr, target, middle + 1, high);
    else return binary_search(arr, target, low, middle - 1);
}

void test() {
    vector<int> arr = {0,1,2,3,5,6,7,8,9,10};

    assert(binary_search(arr, 7, 0, arr.size() - 1) == 6);

    assert(binary_search(arr, 4, 0, arr.size() - 1) == -1);

    assert(binary_search(arr, 1, 0, arr.size() - 1) == 1);

    assert(binary_search(arr, 10, 0, arr.size() - 1) == 9);
}

int main() {
    test();
    return 0;
}

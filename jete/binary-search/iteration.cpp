#include<bits/stdc++.h>

using namespace std;

int binary_search(vector<int> arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while(low <= high) {
        int middle = low + (high - low) / 2;

        if(arr[middle] == target) return middle;
        else if(arr[middle] < target) low = middle + 1;
        else high = middle - 1;
    }

    return -1;
}

void test() {
    vector<int> arr = {0,1,2,3,5,6,7,8,9,10};

    assert(binary_search(arr, 7) == 6);

    assert(binary_search(arr, 4) == -1);

    assert(binary_search(arr, 1) == 1);

    assert(binary_search(arr, 10) == 9);
}

int main() {
    test();
    return 0;
}

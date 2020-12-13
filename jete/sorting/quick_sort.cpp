#include<bits/stdc++.h>

using namespace std;


void print(vector<int> in) {
    for(auto e: in)
        cout<<e<<" ";
    cout<<endl;
}


void quicksort(vector<int>& in, int left, int right) {
    if(left == right) return;

    int count = right - left;
    int pivot_rand = rand() % count;
    int pivot = in[left + pivot_rand];

    int i = left;
    int j = right;
    while(i < j) {
        while(in[i] < pivot) i++;
        while(in[j] > pivot) j--;

        if(i < j) swap(in[i], in[j]);
    }
    if(left < j)
        quicksort(in, left, j-1);
    if(right > i)
        quicksort(in, i+1, right);
}

void test_quicksort() {
    vector<int> in = {5,7,9,3,10,2,11,6,1,4,8};
    vector<int> quickSorted = in;
    quicksort(quickSorted, 0, in.size() - 1);

    sort(in.begin(), in.end());
    for(int i=0; i<in.size(); i++) {
        assert(in[i] == quickSorted[i]);
    }
}

void test() {
    test_quicksort();
}

int main() {
    test();
    return 0;
}

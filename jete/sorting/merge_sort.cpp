#include<bits/stdc++.h>

using namespace std;

/*
void print(vector<int> in) {
    for(auto e: in)
        cout<<e<<" ";
    cout<<endl;
}
*/

vector<int> merge(vector<int> left, vector<int> right) {
    vector<int> res;

    int pointerLeft = 0;
    int pointerRight = 0;
    while(pointerLeft < left.size() && pointerRight < right.size()) {
        if(left[pointerLeft] <= right[pointerRight])
            res.push_back(left[pointerLeft++]);
        else
            res.push_back(right[pointerRight++]);
    }
    while(pointerLeft < left.size())
        res.push_back(left[pointerLeft++]);
    while(pointerRight < right.size())
        res.push_back(right[pointerRight++]);
    return res;
}

vector<int> mergesort(vector<int> in) {
    if(in.size() <= 1) return in;

    int mid = in.size() / 2;
    vector<int> left = mergesort({in.begin(), in.begin() + mid});
    vector<int> right = mergesort({in.begin() + mid, in.end()});
    return merge(left, right);
}

void merge_inplace(vector<int>& in, int left, int middle, int right) {
    int temp[right - left - 1];
    int i = left;
    int j = middle + 1;
    int counter = 0;

    while(i <= middle && j <= right) {
        if(in[i] <= in[j])
            temp[counter++] = in[i++];
        else
            temp[counter++] = in[j++];
    }
    while(i <= middle)
        temp[counter++] = in[i++];
    while(j <= right)
        temp[counter++] = in[j++];

    --counter;
    while(counter >= 0) {
        in[left + counter] = temp[counter];
        --counter;
    }
}

void mergesort_inplace(vector<int>& in, int left, int right) {
    if(left >= right) return;

    int middle = left + (right - left) / 2;
    mergesort_inplace(in, left, middle);
    mergesort_inplace(in, middle+1, right);
    merge_inplace(in, left, middle, right);
}

void test_mergesort() {
    vector<int> in = {5,7,9,3,10,2,11,6,1,4,8};
    vector<int> mergeSorted = mergesort(in);

    vector<int> mergeSortedInplace = in;
    mergesort_inplace(mergeSortedInplace, 0, in.size()-1);

    sort(in.begin(), in.end());
    for(int i=0; i<in.size(); i++) {
        assert(in[i] == mergeSorted[i]);
    }

    for(int i=0; i<in.size(); i++) {
        assert(in[i] == mergeSortedInplace[i]);
    }
}

void test() {
    test_mergesort();
}

int main() {
    test();
    return 0;
}

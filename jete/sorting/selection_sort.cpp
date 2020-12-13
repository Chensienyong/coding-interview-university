#include<bits/stdc++.h>

using namespace std;

void print(vector<int> in) {
    for(auto e: in)
        cout<<e<<" ";
    cout<<endl;
}


void selectionsort(vector<int>& in) {
    for(int i=0; i<in.size(); i++) {
        int idx = i;
        for(int j=i; j<in.size(); j++) {
            if(in[j] < in[idx])
                idx = j;
        }
        swap(in[idx], in[i]);
    }
}

void test_selectionsort() {
    vector<int> in = {5,7,9,3,10,2,11,6,1,4,8};
    vector<int> selectionSorted = in;
    selectionsort(selectionSorted);

    sort(in.begin(), in.end());
    for(int i=0; i<in.size(); i++) {
        assert(in[i] == selectionSorted[i]);
    }
}

void test() {
    test_selectionsort();
}

int main() {
    test();
    return 0;
}

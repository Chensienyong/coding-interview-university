#include<bits/stdc++.h>

using namespace std;

void print(vector<int> in) {
    for(auto e: in)
        cout<<e<<" ";
    cout<<endl;
}


void insertionsort(vector<int>& in) {
    for(int i=1; i<in.size(); i++) {
        int num = in[i];
        int j = i-1;
        while(j >= 0 && in[j] > num) {
            in[j+1] = in[j];
            j--;
        }
        in[j+1] = num;
    }
}

void test_insertionsort() {
    vector<int> in = {5,7,9,3,10,2,11,6,1,4,8};
    vector<int> insertionSorted = in;
    insertionsort(insertionSorted);

    sort(in.begin(), in.end());
    for(int i=0; i<in.size(); i++) {
        assert(in[i] == insertionSorted[i]);
    }
}

void test() {
    test_insertionsort();
}

int main() {
    test();
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

// This problem is exact same as N-Meeting in one room with just inverse (opposite) condition

bool comp(vector<int> &a, vector<int> &b){
    return a[1] < b[1]; // sort arr in asc order based on second index
}

int nonOverlapIntervals(vector<vector<int>> &arr, int n){
    sort(arr.begin(), arr.end(), comp);
    int cnt = 1, lastEndTime = arr[0][1];

    for(int i = 1; i<n; i++){
        if(arr[i][0] >= lastEndTime){
            cnt++;
            lastEndTime = arr[i][1];
        }
    }
    return n - cnt;
}
// TC - O(N log N) + O(N) 
// SC - O(1) 

int main(){
    int n = 4;
    vector<vector<int>> arr = {{1,2},{2,3},{33,14},{1,3}};
    cout << nonOverlapIntervals(arr, n);
}



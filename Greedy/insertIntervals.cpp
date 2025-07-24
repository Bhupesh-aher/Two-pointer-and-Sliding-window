#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    int i = 0;
    int n = intervals.size();

    // non-overlap inrervals - Add intervals before newInterval
    while(i < n && intervals[i][1] < newInterval[0]){
        res.push_back(intervals[i]); 
        i++;
    }
    // overlap intervals
    while(i<n && intervals[i][0] <= newInterval[1]){
        newInterval[0] = min(intervals[i][0], newInterval[0]);
        newInterval[1] = max(intervals[i][1], newInterval[1]);
        i++;
    }
    res.push_back(newInterval);

    // rest of the non-overlap elements - Add the rest of the intervals
    while(i < n) {
        res.push_back(intervals[i]);
        i++;
    }
    return res;
}

// TC - O(N) 
// SC - O(1)

// This is the most optimal solution. Sometimes the better solution is also optimal solution.
// so don't think out of the box. As this is optimal way 

// intervals = {{1,2},{3, 4},{5,7},{8,10},{12, 16}} 
// newInterval {{6, 8}};

// intervals = {{1,2},{3, 4},{7,7},{8,10},{12, 16}} 
// newInterval {{5, 6}};


int main(){
    vector<vector<int>> intervals = {{1,2},{3, 5},{6,7},{8,10}, {12, 16}};
    vector<int> newInterval = {{4, 8}};
    vector<vector<int>> ans = insert(intervals, newInterval);

    cout << "[";
    for (int i = 0; i < ans.size(); ++i) {
        cout << "[" << ans[i][0] << "," << ans[i][1] << "]";
        if (i < ans.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
}




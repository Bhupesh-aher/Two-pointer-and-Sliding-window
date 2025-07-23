#include<bits/stdc++.h>
using namespace std;


struct meeting{
    int start;
    int end;
    int pos;
};

bool comp(meeting m1, meeting m2){
    return m1.end < m2.end;
}

vector<int> maxMeetings(int s[], int e[], int n){

    struct meeting meet[n];
    for(int i = 0; i<n; i++){
        meet[i].start = s[i];
        meet[i].end = e[i];
        meet[i].pos = i + 1;
    }
    sort(meet, meet + n, comp);
    vector<int> ans;

    int cnt = 1, freeTime = meet[0].end;
    ans.push_back(meet[0].pos);

    for(int i = 1; i<n; i++){
        if(meet[i].start > freeTime){
            cnt ++;
            freeTime = meet[i].end;
            ans.push_back(meet[i].pos);
        }
    }
    return ans;
}

// TC - O(2N) + O(N log N) 
// SC - O(3 * N) 

int main(){
    int n = 6;
    int start [] = {0, 3, 1, 5, 5, 8};
    int end [] =   {5, 4, 2, 9, 7, 9};
    
    vector<int> ans = maxMeetings(start, end, n);

    cout<<"The order in which the meetings will be performed is "<<endl;
    for(auto it: ans) cout << it << " ";
}


// sort on base of end time
// start end pos
// (1, 2, 3), (3, 4, 2), (0, 5, 1), (5, 7, 5), (5, 9, 4), (8, 9, 6)
// pos in terms of 1 base indexing

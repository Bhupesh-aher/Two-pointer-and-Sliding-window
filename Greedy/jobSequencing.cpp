#include<bits/stdc++.h>
using namespace std;


// id  profit deadline 
// 1    40      4
// 2    10      1
// 3    40      1
// 4    30      1


struct Job {
    int id;
    int profit;
    int deadline;
};

bool comparison(Job a, Job b){
    return (a.profit > b.profit);
}

pair<int, int> JobScheduling(Job arr[], int n){
    sort(arr, arr + n, comparison);
    int totalProfit = 0, cnt = 0, maxDedline = -1;

    for(int i = 0; i<n; i++){
        maxDedline = max(maxDedline, arr[i].deadline);
    }

    int slot[maxDedline + 1];

    for(int i = 0; i<=maxDedline; i++) slot[i] = -1;


    for(int i = 0; i<n; i++){
        for(int j = arr[i].deadline; j>0; j--){
            if(slot[j] == -1){
                slot[j] = arr[i].id;
                cnt ++;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }
    return {cnt, totalProfit};
}

// TC: O(N log N) + O(N*M).
// O(N log N ) for sorting the jobs in decreasing order of profit. O(N*M) since we are iterating through all N jobs and for every job we are checking from the last deadline, say M deadlines in the worst case.
// SC: O(M) for an array that keeps track on which day which job is performed if M is the maximum deadline available.



// Interviewer will be happy with this solution. but in case the interviewer is slightly into competitive programming he'll ask you to optimize the inner loop (checking the deadline loop)
// and that can be done with DSU (Disjoint set union) 
// beacuse we are looping to figure out which is the first day that is empty. That can be replaced with DSU in O(1). without looping you can straight away get it
// But it will not be required in interview so no need to do perform the DSU


int main(){
    int n = 4;
    Job arr[n] = {{1, 40, 4}, {2, 10, 1}, {3, 40, 1}, {4, 30, 1}};

    pair<int, int> ans = JobScheduling(arr, n);
    cout << ans.first << " " << ans.second;
}




// id   profit    deadline
// 1     20          4
// 2     60          5
// 3     70          6
// 4     65          6
// 5     25          4
// 6     80          2
// 7     10          2
// 8     22          2
#include<bits/stdc++.h>
using namespace std;


int f(int ind, int jumps, vector<int> &nums){
    if(ind >= nums.size() - 1) return jumps;
    int mini = INT_MAX;

    for(int i = 1; i<=nums[ind]; i++){
        mini = min(mini, f(ind + i, jumps + 1, nums));
    }
    return mini;
}
int jump(vector<int>& nums) {
    return f(0, 0, nums);
}

// TC - O(N^N) Exponential 
// SC - O(N) Auxillary stack space



// Memoize with DP
int f(int ind, int jumps, vector<int> &nums, vector<int> dp){
    if(ind >= nums.size() - 1) return jumps;
    if(dp[ind] != -1) return dp[ind];
    int mini = INT_MAX;

    for(int i = 1; i<=nums[ind]; i++){
        mini = min(mini, f(ind + i, jumps + 1, nums, dp));
    }
    return dp[ind] = mini;
}
int jump(vector<int>& nums) {
    vector<int> dp(nums.size(), -1);
    return f(0, 0, nums, dp);
}

// TC - O(N^2) 
// SC - O(N) + O(N) 


// You can further optimize this by doing tabulation. but this problem is not a DP problem. 
// so you can jump to the most optimal approach which is Greedy approach




int jump(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = 0, jumps = 0;
    
    while(r < n-1){
        int farthest = 0;
        for(int i = l; i<=r; i++){
            farthest = max(farthest, i + nums[i]);
        }
        jumps ++;
        l = r + 1;
        r = farthest;
    }
    return jumps;
}

// Instead of recursion we kept a range over here. we convert recursive solution into a range based solution 
// TC - O(N) 
// SC - O(1)

int main(){
    vector<int> nums = {2, 3, 1, 4, 1, 1, 1, 2};   // {2, 3, 1, 1, 4};
    cout << jump(nums);
}
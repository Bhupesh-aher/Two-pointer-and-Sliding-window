#include<bits/stdc++.h>
using namespace std;


// binary count the total no of Subarrays with sum 
// This problem is exactly same as - Count subarray sum equals to k (in array playlist)
// Count subarray sum equals to k in this problem array contains the positve and negative element as well
// in count subarray sum equals to k we saw the brute and better and optimal approach
// now those approaches works here as well (beacuse this is exactly same problem)
// the most optimal approach was using hash with TC - O(N) SC - O(N)
// here we can use that optimal approach and it does works 
// but because this current problem has speical condition that just 1 and 0 in array we can further optimize it. 
// The only reason we can optimize it further is we given special condtion that the array just contains 1 and 0 in it
// we can reduce the SC O(N) to  O(1)

int numSubarraysWithSum(vector<int>& nums, int goal) {
    int cnt = 0;
    int n = nums.size();
    for(int i = 0; i<n; i++){
        int sum = 0;
        for(int j = i; j<n; j++){
            sum += nums[j];
            if(sum == goal) cnt ++;
        }
    }
    return cnt;
}
// TC - O(n^2) 
// SC - O(1) 


int numSubarraysWithSum(vector<int>& nums, int goal) {
    int cnt = 0;
    int n = nums.size();
    int preSum = 0;
    map<int, int> mpp;
    mpp[0] = 1;
    for(int i = 0; i<n; i++){
        preSum += nums[i];
        int remove = preSum - goal;
        cnt += mpp[remove];
        mpp[preSum] ++;
    }
    return cnt;
}
// TC - O(N) 
// SC - O(N) 





int countSubarrays(vector<int> &nums, int goal){
    if(goal < 0) return 0;
    int n = nums.size();
    int left = 0, right = 0, cnt = 0, sum = 0;

    while(right < n){
        sum += nums[right];
        while(sum > goal){
            sum -= nums[left];
            left++;
        }
        cnt += right - left + 1;
        right ++;
    }
    return cnt;
}

int numSubarraysWithSum(vector<int>& nums, int goal) {
    return countSubarrays(nums, goal) - countSubarrays(nums, goal - 1);
}

// TC - (2 * 2N) 
// SC - O(1)



int main(){
    vector<int> nums = {1,0,1,0,1};
    // {1, 0, 0, 1, 1, 0}
    int goal = 2;
    cout << numSubarraysWithSum(nums, goal);
}
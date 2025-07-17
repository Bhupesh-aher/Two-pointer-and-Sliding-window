#include<bits/stdc++.h>
using namespace std;

// we can convert this problem into - find largest subarray with at most k zeros


int maxConsecutiveOnes(vector<int> &nums, int k) {
    int maxLen = 0;
    int n = nums.size();
    for(int i = 0; i<n; i++){
        int zeros = 0;
        for(int j = i; j<n; j++){
            if(nums[j] == 0) zeros++;
            if(zeros > k) break;
            maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}
// TC - O(n^2) 
// SC - O(1)



int maxConsecutiveOnes(vector<int>& nums, int k) {
    int maxLen = 0;
    int n = nums.size();
    int left = 0, right = 0;
    int zeros = 0;
    while(right < n){
        if(nums[right] == 0) zeros ++;
        while(zeros > k){
            if(nums[left] == 0) zeros --;
            left++;
        }
        if(zeros <= k) {
            maxLen = max(maxLen, right - left + 1);
        }
        right ++;
    }   
    return maxLen;
}
// TC - O(2N) 
// SC - O(1)



int maxConsecutiveOnes(vector<int>& nums, int k) {
    int maxLen = 0;
    int n = nums.size();
    int left = 0, right = 0;
    int zeros = 0;
    while(right < n){
        if(nums[right] == 0) zeros ++;
        if(zeros > k){
            if(nums[left] == 0) zeros --;
            left++;
        }
        if(zeros <= k) {
            maxLen = max(maxLen, right - left + 1);
        }
        right ++;
    }   
    return maxLen;
}

// TC - O(N) 
// SC - O(1)

int main(){
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    cout << maxConsecutiveOnes(nums, k);
}
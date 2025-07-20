#include<bits/stdc++.h>
using namespace std;

// This problem is exactly same as previous problem which is binary subarray with sum 
// just the problem setter has twisted words here and there

// we can covert this problem into previous problem as they are exactly same problems 



// consider all odd numbers as 1
// and consider all even number as 0
// [1 5 2 1 1]  to 
// [1 1 0 1 1] and now calculate no of subarrays with sum k = 3
// there will be total 2 subarrays with sum k = 3
// and that is the ans if we see in original array 
// [1, 5, 2, 1] [5, 2, 1, 1] these both subarrays has 3 odd numbers which is equal to k
// so pick the exact code from previous problem the only change is when adding and subtracting from sum do %2 operation
// so when element is odd, %2 will store it as 1 and when element is even then, %2 will store it as 0
// this way we can covert this problem into the previous problem as they are exaclty same just problem setter has twisted some words 



int countSubarrays(vector<int> &nums, int goal){
    if(goal < 0) return 0;
    int n = nums.size();
    int left = 0, right = 0, cnt = 0, sum = 0;

    while(right < n){
        sum += nums[right] % 2;
        while(sum > goal){
            sum -= nums[left] % 2;
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

int numberOfSubarrays(vector<int>& nums, int k) {
    return numSubarraysWithSum(nums, k);
}

// TC - (2 * 2N) 
// SC - O(1)

int main(){
    vector<int> nums = {1, 5, 2, 1, 1};
    int k = 3;
    cout << numberOfSubarrays(nums, k);
}
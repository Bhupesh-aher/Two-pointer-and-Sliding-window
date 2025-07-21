#include<bits/stdc++.h>
using namespace std;

// This problem also comes under the pattern with which we solve last 2 problems

int subarraysWithKDistinct(vector<int>& nums, int k) {
    int cnt = 0;
    int n = nums.size();
    for(int i = 0; i<n; i++){
        map<int, int> mpp;
        for(int j = i; j<n; j++){
            mpp[nums[j]]++;
            if(mpp.size() == k) cnt++;
            else if(mpp.size() > k) break;
        }
    }
    return cnt;
}
// TC - O(n^2) 
// SC- O(n) 




int numberOFSubarrays(vector<int> &nums, int k){
    int n = nums.size();
    int left = 0, right = 0, cnt = 0;
    map<int, int> mpp;
    while(right < n){
        mpp[nums[right]]++;
        while(mpp.size() > k){
            mpp[nums[left]] --;
            if(mpp[nums[left]] == 0) mpp.erase(nums[left]);
            left ++;
        }
        cnt += right - left + 1;
        right ++;
    }
    return cnt;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
    return numberOFSubarrays(nums, k) - numberOFSubarrays(nums, k - 1);
}

// TC - O(2 * 2N) 
// SC - O(N)



int main(){
    vector<int>nums = {1,2,1,3,4};
    int k = 3;
    cout << subarraysWithKDistinct(nums, k);
}
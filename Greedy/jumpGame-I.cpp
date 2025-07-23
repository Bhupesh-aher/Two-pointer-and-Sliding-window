#include<bits/stdc++.h>
using namespace std;


bool canJump(vector<int>& nums) {
    int maxInd = 0;
    for(int i = 0; i<nums.size(); i++){
        if(i > maxInd) return false;
        maxInd = max(maxInd, i + nums[i]);
    }
    return true;
}

// TC - O(N)
// SC - O(1) 






int main(){
    vector<int> nums = {1, 2, 4, 1, 1, 0, 2, 5};   // {1, 2, 3, 1, 1, 0, 2, 5};
    cout << canJump(nums);
}
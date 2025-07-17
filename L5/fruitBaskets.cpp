#include<bits/stdc++.h>
using namespace std;

// we can convert this problem into - max length subarray with at most 2 types of unique numbers 


int totalFruit(vector<int>& fruits) {
    int n = fruits.size();
    int maxLen = 0;
    for(int i = 0; i<n; i++){
        set<int> st;
        for(int j = i; j<n; j++){
            st.insert(fruits[j]);
            if(st.size() > 2) break;
            maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}
// TC - O(n^2) 
// SC - O(3) // for set as we are storing at max 3 elements in set


int totalFruit(vector<int>& nums) {
    int n = nums.size();
    int maxLen = 0;
    int left = 0, right = 0;
    map<int, int> mpp;
    // nums[i] count

    while(right < n){
        mpp[nums[right]] ++;
        if(mpp.size() > 2){
            while(mpp.size() > 2){
                mpp[nums[left]] --;
                if(mpp[nums[left]] == 0) mpp.erase(nums[left]);
                left ++;
            }
        }
        if(mpp.size() <= 2) {
            maxLen = max(maxLen, right - left + 1);
        }
        right ++; 
    }
    return maxLen;
}

// TC - O(2N) 
// SC - O(3) 



int totalFruit(vector<int>& nums) {
    int n = nums.size();
    int maxLen = 0;
    int left = 0, right = 0;
    map<int, int> mpp;

    while(right < n){
        mpp[nums[right]] ++;
        if(mpp.size() > 2){
            mpp[nums[left]] --;
            if(mpp[nums[left]] == 0) mpp.erase(nums[left]);
            left ++;
        }
        if(mpp.size() <= 2) {
            maxLen = max(maxLen, right - left + 1);
        }
        right ++; 
    }
    return maxLen;
}

// TC - O(N) 
// SC - O(3) 



int main(){
    vector<int> fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    
    cout << totalFruit(fruits);
}
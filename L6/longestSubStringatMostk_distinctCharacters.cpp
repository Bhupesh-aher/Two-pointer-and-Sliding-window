#include<bits/stdc++.h>
using namespace std;

// we can convert this problem into - this problem is exact same as previous problem. just the problem statment is changed


int longestSubstring(string s, int k) {
    int n = s.length();
    int maxLen = 0;
    for(int i = 0; i<n; i++){
        set<char> st;
        for(int j = i; j<n; j++){
            st.insert(s[j]);
            if(st.size() > k) break;
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
}
// TC - O(n^2) 
// SC - O(3) // for set as we are storing at max 3 char in set


int longestSubstring(string s, int k) {
    int n = s.length();
    int maxLen = 0;
    int left = 0, right = 0;
    map<char, int> mpp;
    // s[right] count

    while(right < n){
        mpp[s[right]] ++;
        if(mpp.size() > k){
           while(mpp.size() > k){
            mpp[s[left]] --;
            if(mpp[s[left]] == 0) mpp.erase(mpp[left]);
            left++;
            }
        }
        if(mpp.size() <= k) {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    return maxLen;
}

// TC - O(2N) + log(26) 
// SC - O(26)  // considering all characters in string is lower case only




int longestSubstring(string s, int k) {
    int n = s.length();
    int maxLen = 0;
    int left = 0, right = 0;
    map<char, int> mpp;
    // s[right] count

    while(right < n){
        mpp[s[right]] ++;
        if(mpp.size() > k){
            mpp[s[left]] --;
            if(mpp[s[left]] == 0) mpp.erase(mpp[left]);
            left++;
        }
        if(mpp.size() <= k) {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    return maxLen;
}

// TC - O(N) + log(26) 
// SC - O(26)

int main(){
    string s = "aaabbccd";
    int k = 2;
    cout << longestSubstring(s, k);
}
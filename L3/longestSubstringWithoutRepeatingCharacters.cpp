#include<bits/stdc++.h>
using namespace std;


int lengthOfLongestSubstring(string s) {
    int maxLen = 0;
    for(int i = 0; i<s.length(); i++){
        int hash[256] = {0};
        for(int j = i; j<s.length(); j++){
            if(hash[s[j]] == 1) break;
            maxLen = max(maxLen, j - i + 1);
            hash[s[j]] = 1;
        }
    }
    return maxLen;
}
// TC - O(n^2) 
// SC - O(256) 


int lengthOfLongestSubstring(string s) {
    int maxLen = 0;
    int hash[256] = {-1};
    for (int i = 0; i < 256; ++i) hash[i] = -1;

    int l = 0, r = 0;
    while(r < s.length()){
        if(hash[s[r]] != -1){
            if(hash[s[r]] >= l){
                l = hash[s[r]] + 1;
            }
        }
        maxLen = max(maxLen, r - l + 1);
        hash[s[r]] = r;
        r ++;
    }
    return maxLen;
}

// TC - O(n)
// Sc - O(256)  

int main(){
    string s = "cadbzabcd";
    cout << lengthOfLongestSubstring(s);
}
#include<bits/stdc++.h>
using namespace std;


int characterReplacement(string s, int k) {
    int n = s.length();
    int maxLen = 0;
    for(int i = 0; i<n; i++){
        int hash[26] = {0};
        int maxFreq = 0;
        for(int j = i; j<n; j++){
            hash[s[j] - 'A']++;
            maxFreq = max(maxFreq, hash[s[j] - 'A']);
            int change = (j - i + 1) - maxFreq;
            if(change <= k) {
                maxLen = max(maxLen, j - i + 1);
            }
            else break;
        }
    }   
    return maxLen;
}

// TC - O(n^2) 
// SC - O(26) 


int characterReplacement(string s, int k) {
    int n = s.length();
    int maxLen = 0;
    int left = 0, right = 0, maxFreq = 0;
    int hash[26] = {0};
    while(right < n){
        hash[s[right] - 'A']++;
        maxFreq = max(maxFreq, hash[s[right] - 'A']);

        while((right - left + 1) - maxFreq > k){
            hash[s[left] - 'A'] --;
            maxFreq = 0;
            for(int i = 0; i<26; i++) maxFreq = max(maxFreq, hash[i]);
            left ++;
        }
        if((right - left + 1) - maxFreq <= k){
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    return maxLen;
}

// TC - O(2N) * 26
// SC - O(26)





int characterReplacement(string s, int k) {
    int n = s.length();
    int maxLen = 0;
    int left = 0, right = 0, maxFreq = 0;
    int hash[26] = {0};
    while(right < n){
        hash[s[right] - 'A']++;
        maxFreq = max(maxFreq, hash[s[right] - 'A']);

        if((right - left + 1) - maxFreq > k){
            hash[s[left] - 'A'] --;
            left ++;
        }
        if((right - left + 1) - maxFreq <= k){
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    return maxLen;
}

// TC - O(N) 
// SC - O(26) 


int main(){
    string s = "AABABBA";
    int k = 2;
    cout << characterReplacement(s, k);
}
#include<bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    int n = s.length();
    int m = t.length();
    int minLen = INT_MAX;
    int startIndex = -1;
    for(int i = 0; i<n; i++){
        int cnt = 0;
        int hash[256] = {0};
        for(int j = 0; j<m; j++) hash[t[j]]++;
        for(int j = i; j<n; j++){
            if(hash[s[j]] > 0) cnt++;
            hash[s[j]] --;
            if(cnt == m) {
                if(j - i + 1 < minLen){
                    minLen = j - i + 1;
                    startIndex = i;
                    break;
                }
            }
        }
    }
    if (startIndex == -1) return "";
    return s.substr(startIndex, minLen);
}

// TC - O(n^2) 
// SC - O(256)


string minWindow(string s, string t) {
    int n = s.length();
    int m = t.length();
    int minLen = INT_MAX;
    int startIndex = -1;
    int hash[256] = {0};
    for(int i = 0; i<m; i++) hash[t[i]] ++;
    int left = 0, right = 0, cnt = 0;
    while(right < n){
        if(hash[s[right]] > 0) cnt++;
        hash[s[right]] --;
        while(cnt == m){
            if(right - left + 1 < minLen){
                minLen = right - left + 1;
                startIndex = left;
            }
            hash[s[left]]++;
            if(hash[s[left]] > 0) cnt --;
            left ++;
        }
        right ++;
    }

    return startIndex == -1 ? "" : s.substr(startIndex, minLen);

}

// TC - O(2N) + O(m)
// SC - O(256) 

int main(){
    string s = "ddaaabbca";
    string t = "abc";
    cout << minWindow(s, t);
}
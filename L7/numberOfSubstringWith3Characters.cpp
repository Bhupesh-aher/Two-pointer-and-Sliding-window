#include<bits/stdc++.h>
using namespace std;

// Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.



int numberOfSubstrings(string s) {
    int cnt = 0;
    for(int i = 0; i<s.length(); i++){
        int hash[3] = {0};
        for(int j = i; j<s.length(); j++){
            hash[s[j] - 'a'] = 1;        
            if(hash[0] + hash[1] + hash[2] == 3) cnt++;    // means all 3 charcters are there in substring
        }
    }
    return cnt;
}
// TC - O(n^2) 
// SC - O(1)

// 3 size hash arr beacuse we only have 3 diff characters in string
// when [s[j] - 'a'] we subtrack with char 'a' then the  charcter from a to z store  from 0th to 25th index in sequence
// a - 0th index b - 1st index  c - 2rd index  d - 3th index and so on





int numberOfSubstrings(string s) {
    int cnt = 0;
    int n = s.length();
    for(int i = 0; i<s.length(); i++){
        int hash[3] = {0};
        for(int j = i; j<s.length(); j++){
            hash[s[j] - 'a'] = 1;
            if(hash[0] + hash[1] + hash[2] == 3) {
                cnt += (n - j);
                break;
            }
        }
    }
    return cnt;
}

// slight improvment as this apporach will help us to get optimial solution





 int numberOfSubstrings(string s) {
    int cnt = 0;
    int n = s.length();
    int hash[3] = {-1, -1, -1};
    for(int i = 0; i<n; i++){
        hash[s[i] - 'a'] = i;
        if(hash[0] != -1 && hash[1] != -1 && hash[2] != -1){
            int mini = min(hash[0], hash[1]);
            cnt += 1 + min(mini, hash[2]);
        } 
    }
    return cnt;
}

// TC - O(N) 
// SC - O(1)


int main(){
    string s = "bbacba";
    cout << numberOfSubstrings(s);
}
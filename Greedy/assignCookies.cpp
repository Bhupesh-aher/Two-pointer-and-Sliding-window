#include<bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    int n = g.size();
    int m = s.size();
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int l = 0, r = 0;
    while(l < m && r < n){
        if(g[r] <= s[l]) {
            r++;
        }
        l ++;
    }
    return r;
}

// TC - O(n log n) + O(m log m) + O(m) 

int main(){
    vector<int> g = {1, 5, 3, 3, 4};
    vector<int> s = {4, 2, 1, 2, 1, 3};
    cout << findContentChildren(g, s);
}
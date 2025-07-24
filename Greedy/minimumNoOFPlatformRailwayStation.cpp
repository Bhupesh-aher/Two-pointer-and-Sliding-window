#include<bits/stdc++.h>
using namespace std;



int countPlatforms(vector<int> &arrival, vector<int>& dep, int n){
    int maxCnt = 1;
    for(int i = 0; i<n; i++){
        int cnt = 1;
        for(int j = 0; j<n; j++){
            if(i != j){
                 if((arrival[i] >= arrival[j] && arrival[i] <= dep[j]) 
                 || (arrival[j] >= arrival[i] && arrival[j] <= dep[i])){
                    cnt ++;
                }
            } 
        }
        maxCnt = max(maxCnt, cnt);
    }
    return maxCnt;
}

// TC - O(N^2) 
// SC - O(1)



int countPlatforms(vector<int> &arrival, vector<int>& dep, int n){
    sort(arrival.begin(), arrival.end());
    sort(dep.begin(), dep.end());
    int i= 0, j = 0;
    int maxCnt = 0, cnt = 0;

    while(i < n && j < n){
        if(arrival[i] <= dep[j]){
            cnt ++;
            i ++;
        }
        else {
            cnt --;
            j ++;
        }
        maxCnt = max(maxCnt, cnt);
    }
    return maxCnt;
}

// TC - O 2(N log N) + O(2N) 
// SC - O(1) 

int main(){
    vector<int> arrival={900,945,955,1100,1500,1800};
    vector<int> dep ={920,1200,1130,1150,1900,2000};
    int n = arrival.size();
    cout<<"Minimum number of Platforms required "<<countPlatforms(arrival, dep, n)<<endl;
}




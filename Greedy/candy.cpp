#include<bits/stdc++.h>
using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> left(n);
    vector<int> right(n);

    left[0] = 1, right[n-1] = 1;
    for(int i = 1; i<n; i++){
        if(ratings[i] > ratings[i-1]){
            left[i] = left[i-1] + 1;
        }
        else left[i] = 1;
    }
    for(int i = n - 2; i>=0; i--){
        if(ratings[i] > ratings[i+1]){
            right[i] = right[i+1] + 1;
        }
        else right[i] = 1;
    }

    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += max(left[i], right[i]);
    }
    return sum;
}

// TC - O(2N) + O(N)
// SC - O(2N) 




int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> left(n);

    left[0] = 1;
    for(int i = 1; i<n; i++){
        if(ratings[i] > ratings[i-1]){
            left[i] = left[i-1] + 1;
        }
        else left[i] = 1;
    }
    int right = 1;
    int sum = max(1, left[n-1]);
    for(int i = n - 2; i>=0; i--){
        if(ratings[i] > ratings[i+1]){
            right = right + 1;
        }
        else right = 1;
        sum += max(left[i], right);
    }
    return sum;
}

// TC - O(2N)
// SC - O(N) 



// Slope Approach - 
// ratings = {0, 2, 4, 7, 6, 5, 4, 2, 1, 1, 1, 2, 3, 4, 2, 1, 1}

int candy(vector<int>& ratings) {
    int n = ratings.size();
    int sum = 1, i = 1;
    while(i <n){
        if(i < n && ratings[i] == ratings[i-1]){
            sum +=1; 
            i++;
            continue;
        }
        int peak = 1;
        while(i < n && ratings[i] > ratings[i -1]){
            peak += 1;
            sum += peak;
            i ++;
        }
        int down = 1;
        while(i < n && ratings[i] < ratings[i-1]){
            sum += down;
            down += 1;
            i++;
        }
        if(down > peak) sum += down - peak;
    }
    return sum;
}

// TC - O(N)
// SC - O(1)

int main(){
    vector<int> ratings = {1, 3, 2, 1};
    cout << candy(ratings);
}
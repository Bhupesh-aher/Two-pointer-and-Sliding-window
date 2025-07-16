#include<bits/stdc++.h>
using namespace std;


int maxScore(vector<int>& cardPoints, int k) {
    int leftSum = 0, rightSum = 0;
    int maxPoints = 0;
    for(int i = 0; i<=k-1; i++){
        leftSum += cardPoints[i];
    }
    maxPoints = leftSum;
    int rightInd = cardPoints.size() - 1;

    for(int i = k-1; i>=0; i--){
        leftSum -= cardPoints[i];
        rightSum += cardPoints[rightInd];
        rightInd --;

        maxPoints = max(maxPoints, leftSum + rightSum);
    }
    return maxPoints;
}

// TC - O(k * 2) 
// SC - O(1)

int main(){
    vector<int> nums =  {6, 2, 3, 4, 7, 2, 1, 7, 1};
    int k = 4;
    cout << maxScore(nums, k);
    

}
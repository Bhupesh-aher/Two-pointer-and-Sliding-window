#include<bits/stdc++.h>
using namespace std;

 bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;
    for(int i = 0; i<bills.size(); i++){
        if(bills[i] == 5) five++;
        else if(bills[i] == 10){
            if(five) {
                five --;
                ten ++;
            }
            else return false;
        }
        else {
            if(five && ten) {
                five --;
                ten --;
            }
            else if(five >= 3) {
                five -= 3;
            }
            else return false;
        }
    }
    return true;
}

// TC - O(N)
// SC - O(1) 

int main(){
    vector<int> bills = {1, 5, 3, 3, 4};
    cout << lemonadeChange(bills);
}
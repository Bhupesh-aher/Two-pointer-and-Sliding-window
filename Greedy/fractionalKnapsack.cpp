#include<bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

bool comp(Item a, Item b){
    double r1 = (double) a.value / (double) a.weight;
    double r2 = (double) b.value / (double) b.weight;
    return r1 > r2;
}

double fractionalKnapsack(Item arr[], int w, int n){
    sort(arr, arr + n, comp);

    double totalval = 0.0;

    for(int i = 0; i<n; i++){
        if(arr[i].weight <= w){
            totalval += arr[i].value;
            w -= arr[i].weight;
        }
        else {
            totalval += (arr[i].value / (double) arr[i].weight) * (double) w;
            break;
        }
    }
    return totalval;
}

// TC - O(N log N) + O(N) 
// SC - O(N) 

int main(){
    int n = 4;
    Item arr[] = {{100, 20}, {60, 10}, {100, 50}, {200, 50}};
    int w = 90;
    cout << fractionalKnapsack(arr, w, n);
}
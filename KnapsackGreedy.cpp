#include<bits/stdc++.h>
using namespace std;

struct item{
    int profit;
    int weight;
    item(int profit,int weight){
        this->profit=profit;
        this->weight=weight;
    }
};

static bool meracmp(item a,item b){
    double r1=(double)a.profit/(double)a.weight;
    double r2=(double)b.profit/(double)b.weight;
    return r1>r2;
}

double fractionalKnapsack(int W,item arr[],int N){
    sort(arr,arr+N,meracmp);
    double ans=0;
    for(int i=0;i<N;i++){
        // if item can come - add completely
        if(arr[i].weight <= W){
            ans+=arr[i].profit;
            W -= arr[i].weight;
        }
        else{
            //add fraction
            ans+=arr[i].profit*((double)W/(double)arr[i].weight);
            break;
        }
    }

    return ans;
}

int main(){
    int W = 50;
    item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    cout << fractionalKnapsack(W, arr, N);
    return 0;
}
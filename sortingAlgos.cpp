#include<bits/stdc++.h>
using namespace std;
void insertionSort(vector<int> &v){
    for(int i=1;i<v.size();i++){
        for(int j=0;j<i;j++){
            if(v[i]<v[j]){
                swap(v[i],v[j]);
            }
        }
    }
    return;
}

void selectionSort(vector<int> &v){
    for(int i=v.size()-1;i>=0;i--){
        int maxi = v[i];
        int idx = i;
        for(int j=0;j<=i;j++){
            if(v[j]>maxi){
                maxi = v[j];
                idx = j;
            }
        }
        swap(v[i],v[idx]);
    }
}

void bubbleSort(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size() - i - 1; j++) {  
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

int main(){
    vector<int> v = {5,2,3,4,1};
    bubbleSort(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
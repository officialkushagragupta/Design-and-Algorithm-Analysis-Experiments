// Max Heap is used -> i.e. Root node->val  > parent node->val
#include<iostream>
#include<vector>
using namespace std;

class heap{
    public:
        vector<int> vec;
        int size = 0;
        
        heap(){
            vec.push_back(-1);
        }
        
        void insert(int val){
            vec.push_back(val);
            size += 1;
            int index = size;
            while(index > 1){
                int parent = index/2;
                if(vec[parent] < vec[index]){
                    swap(vec[parent],vec[index]);
                    index = parent;
                }
                else{
                    return;
                }
            }
        }

        void deleteFromHeap(){
            if(size==0){
                cout<<"Nothing to delete";
                return;
            }

            // Step 1: Put last node as root node
            vec[1] = vec[size];
            vec.pop_back();
            size--;

            // Step 2: Take root node to its correct position
            int i=1;
            while(i<size){
                int leftIndex = 2*i;
                int rightIndex = 2*i+1;

                if(leftIndex<size && vec[i]<vec[leftIndex]){
                    swap(vec[i],vec[leftIndex]);
                    i=leftIndex;
                }
                else if(rightIndex<size && vec[i]<vec[rightIndex]){
                    swap(vec[i],vec[rightIndex]);
                    i=rightIndex;
                }
                else{
                    // already shi jagah pe pada hua hai
                    return;
                }
            }
        }

        void print(){
            for(int i = 1; i <= size; i++){
                cout << vec[i] << " ";
            }
            cout << endl;
        }
};

void heapify(vector<int> arr, int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;
    if(left <= n  && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }

}

void heapSort(vector<int> arr,int n){
    int size=n;
    while(size>1){
        // Step1. SWAP
        swap(arr[size],arr[1]);
        size--;

        // Step2.
        heapify(arr,size,1);
    }
}

int main(){

    heap h;
    h.insert(4);
    h.insert(3);
    h.insert(5);
    h.insert(1);
    h.insert(2);
    h.print();
    h.deleteFromHeap();
    h.print();

    vector<int> arr={-1,54,53,55,52,50};
    int n = 5;
    for(int i = n/2;i>0;i--){
        heapify(arr,n,i);
    }
    
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }

    heapSort(arr,n);
    cout<<endl;
 
     for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}

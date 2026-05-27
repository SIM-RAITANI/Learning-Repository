#include<iostream>
#include<vector>
using namespace std;
class BinaryHeap{
    public:
    int size;
    int capacity;
    vector<int> arr;
    BinaryHeap(int cap){
        capacity=cap;
        size=0;
        arr.resize(capacity);
    }

    int parent(int i){
        return (i-1)/2;
    }

    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }
    void heapify(int idx){
        int smallest=idx;

        int left=2*idx+1;
        int right=2*idx+2;

        if (left<size && arr[left]<arr[smallest]){
            smallest=left;
        }
        if (right<size && arr[right]<arr[smallest]){
            smallest=right;
        }

        if (smallest != idx){
            swap(arr[idx],arr[smallest]);
            heapify(smallest);
        }
    }
    void insert(int ele){
        if (size == capacity){
            cout << "Heap is full" << endl;
            return ;
        }

        arr[size]=ele;
        int idx=size;
        size++;

        while(idx!=0 && arr[parent(idx)]>arr[idx]){
            swap(arr[parent(idx)],arr[idx]);
            idx=parent(idx);
        }
        cout << ele << " Inserted successfully" << endl;
    }

    void deleteMin(){
        if (size == 0){
            cout << "Heap is empty" << endl;
            return;
        }
        size--;
        swap(arr[size],arr[0]);
        heapify(0);
        cout << "Minimum Element deleted successfully" << endl;
    }
    int getMin(){
        if (size == 0){
            cout << "Heap is empty" << endl;
            return INT_MIN;
        }
        return arr[0];
    }
    void decreaseKey(int idx,int val){
        arr[idx]=val;

        while(idx != 0 && arr[parent(idx)]>arr[idx]){
            swap(arr[parent(idx)],arr[idx]);
            idx=parent(idx);
        }
        cout << "The key value has been set to a new value" << endl;
    }
    void deleteKey(int idx){
        decreaseKey(idx,INT_MIN);
        deleteMin();
        cout << "The key value has been deleted successfully" << endl;
    }
    void printHeap(){
        for (int i=0;i<size;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    BinaryHeap bh(10);
    bh.insert(5);
    bh.insert(3);
    bh.insert(8);
    bh.insert(1);
    bh.insert(4);
    bh.printHeap();
    cout << "Minimum Element: " << bh.getMin() << endl;
    bh.deleteMin();
    bh.printHeap();
    bh.decreaseKey(2, 0);
    bh.printHeap();
    bh.deleteKey(1);
    bh.printHeap();
    return 0;
}
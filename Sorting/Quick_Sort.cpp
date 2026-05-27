#include <iostream>
#include<vector>
using namespace std;
int partition(int low,int high,vector<int> &arr){
    int pivot=arr[high];

    int i=low-1;

    for (int j=low;j<high;j++){
        if (arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;

}
void quickSort(int low,int high,vector<int> &arr){
    if (low<high){
        int pivotIndex=partition(low,high,arr);

        quickSort(low,pivotIndex-1,arr);
        quickSort(pivotIndex+1,high,arr);
    }
}
int main(){
    vector<int> arr={4,7,1,3,2,8};
    int n=arr.size();
    quickSort(0,n-1,arr);
    for (int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}